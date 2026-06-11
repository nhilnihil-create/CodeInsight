#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
    ost<<"{"<<p.first<<","<<p.second<<"}";
    return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
    ost<<"{";
    for(int i=0;i<v.size();i++){
        if(i)ost<<",";
        ost<<v[i];
    }
    ost<<"}";
    return ost;
}

int H,W;
int N;

vint lis[222222];

signed main(){
    scanf("%lld%lld%lld",&H,&W,&N);
    rep(i,N){
        int y,x;
        scanf("%lld%lld",&y,&x);
        y--;x--;
        lis[y].pb(x);
    }

    rep(i,H)sort(all(lis[i]));
    int r=1;

    rep(i,H-1){
        if(lis[i+1].size()&&lis[i+1][0]<r){
            cout<<i+1<<endl;
            return 0;
        }
        if(lis[i+1].size()==0||lis[i+1][0]>r)r++;
        chmin(r,W);
    }
    
    cout<<H<<endl;
    return 0;
}