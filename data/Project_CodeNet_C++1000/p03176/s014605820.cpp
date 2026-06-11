//
//  main.cpp
//  DPq2
#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using P=pair<int,int>;
using ll = long long;
vector<ll>dat;
int leaf=1;
void update(int i,ll x){
    i+=leaf-1; // 更新したい葉の番号
    dat[i]=x;
    while(i>0){
        i=(i-1)/2; // 親の番号
        dat.at(i)=max(dat.at(i*2+1),dat.at(i*2+2));
    }
}
// 左の子　dat.at(2*i+1)
// 右の子　dat.at(2*i+2)
// 親　dat.at((i-1)/2)
ll query_sub(int a,int b,int k,int l,int r){
    // k:現在のノード　[l,r):dat[k]が表している区間
    if(r<=a||b<=l){
        return 0;
    } else if(a<=l && r<=b){
        return dat[k];
    } else {
        ll vl=query_sub(a, b, k*2+1, l, (l+r)/2);
        ll vr=query_sub(a, b, k*2+2, (l+r)/2, r);
        return max(vl,vr);
    }
}
ll query(int a,int b){return query_sub(a,b,0,0,leaf);} // [a,b)の最大値を求める

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    vector<vector<int>> hana(n,vector<int>(3)); // 0:h 1:i 2:a
    rep(i,n) cin>>hana.at(i).at(0); // h:高さ
    rep(i,n) cin>>hana.at(i).at(2); // a:美しさ
    rep(i,n) hana.at(i).at(1)=i; // i:並び順
    sort(hana.begin(),hana.end()); // 高さの昇順
    int x=0;
    while(n>leaf){
        leaf=1<<x;
        x++; // nより大きい数（2のx乗）を求める
    }
    dat.resize(2*(1<<x)-1);
    for(int now=0;now<n;now++){
        int ord=hana.at(now).at(1);
        update(ord,query(0, ord)+hana.at(now).at(2));
    }
    cout<<dat.at(0)<<endl;
    return 0;
}
