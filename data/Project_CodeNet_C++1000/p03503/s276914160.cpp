#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define ll long long
const ll INF = 1LL<<60;
int main(){//0-index
    int n; cin >> n;
    vector<vector<int> > F(n,vector<int>(14));
    vector<vector<int> > P(n,vector<int>(15));
    rep(i,n){
        rep(j,10){
            cin >> F[i][j];
        }
    }
    rep(i,n){
        rep(j,11){
            cin >> P[i][j];
        }
    }
    ll ans=-INF;
    for(int bit=1;bit<(1<<10);++bit){//bitの2進数表記した時に1である桁に対応した日に自分が営業している
        vector<int> ct(n);
        rep(i,n) ct[i]=0;
        ll res=0;
        rep(i,10){//i番目の時間帯に営業しているか調べる
            if(bit & (1<<i)){//i番目の時間帯に自分の店が営業している時
                rep(j,n){
                    ct[j]+=F[j][i];//j番目の店が時間帯iに営業しているか
                }
            }
        }
        rep(i,n) res += P[i][ct[i]];
        ans = max(ans,res);
    }
    cout << ans << endl;
    return 0;
}