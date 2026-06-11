#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int n,m;
    cin >> n>>m;
    int foods[m]={0};
    rep(i,n){
        int k;
        cin >>k;
        rep(j,k){
            int like;
            cin >> like;
            foods[like-1]++;
        }
    }
    int ans{0};
    rep(i,m){
        if(foods[i]==n)
            ans++;
    }
    cout<<ans<<endl;
}