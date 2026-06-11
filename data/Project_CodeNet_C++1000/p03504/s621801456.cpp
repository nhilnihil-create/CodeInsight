#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
#define fi first
#define se second
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

lint segdata[(1<<19)-1];
lint lazy[(1<<19)-1];

lint neutral(){
    return -INF; //単位元
}
lint calc(lint a,lint b){
    return max(a,b); //演算 デフォルトでは最小値
}
void seginit(){
    rep(i,(1<<19)-1) segdata[i]=neutral();
}
void update(lint i,lint x){ // i番目の値をxに更新 rangeadd()の後に使ったらだめ 単位元が0以外の時だけ使う
    i+=(1<<18)-1;
    segdata[i]=x;
    while(i>0){
        i=(i-1)/2;
        segdata[i]=calc(segdata[i*2+1],segdata[i*2+2]);
    }
}
void eval(lint k,lint l,lint r){
    if(lazy[k]){
        segdata[k]+=lazy[k]/(r-l);
        if(r-l>1) lazy[2*k+1]+=lazy[k]/2,lazy[2*k+2]+=lazy[k]/2;
        lazy[k]=0;
    }
}
void add(lint a,lint b,lint x,lint k,lint l,lint r){
    eval(k,l,r);
    if(r<=a || b<=l) return;
    if(a<=l && r<=b){
        lazy[k]+=(r-l)*x;
        eval(k,l,r);
    }
    else{
        add(a,b,x,2*k+1,l,(l+r)/2);
        add(a,b,x,2*k+2,(l+r)/2,r);
        segdata[k]=calc(segdata[2*k+1],segdata[2*k+2]);
    }
}
lint seg(lint a,lint b,lint k,lint l,lint r){
    eval(k,l,r);
    if(r<=a || b<=l) return neutral();
    if(a<=l && r<=b) return segdata[k];
    else{
        lint left=seg(a,b,k*2+1,l,(l+r)/2);
        lint right=seg(a,b,k*2+2,(l+r)/2,r);
        return calc(left,right);
    }
}
lint query(lint a,lint b){
    return seg(a,b+1,0,0,1<<18); //a~b(閉区間）の範囲での演算
}
void rangeadd(lint a,lint b,lint x){ //a~b(閉区間)にxを加算
    add(a,b+1,x,0,0,1<<18); 
    return;
}

int main(void){
    seginit();
    int N,C;
    cin >> N >> C;
    rangeadd(0,150000,INF);
    pair<int,pint> movie[N];
    rep(i,N) cin >> movie[i].se.fi >> movie[i].se.se >> movie[i].fi;
    sort(movie,movie+N);
    int before=-1,cha=-1;
    rep(i,N){
        if(cha!=movie[i].fi) before=-1,cha=movie[i].fi;
        if(before==movie[i].se.fi) movie[i].se.fi++;
        rangeadd(movie[i].se.fi,movie[i].se.se,1);
        before=movie[i].se.se;
    }
    cout << query(0,150000) << endl;
}