#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    int n,c;cin >>n>>c;
    vector<vector<ll>>d(c,vector<ll>(c));
    vector<vector<ll>>cnt(3,vector<ll>(c,0));
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >>d[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ll a;cin >>a;a--;
            int k=(i+j)%3;
            cnt[k][a]++;
        }
    }
    ll ans=INFll;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int k = 0; k < c; ++k) {
                if(i==j||j==k||i==k)continue;
                ll now=0;
                for (int l = 0; l < c; ++l) {
                    now+=d[l][i]*cnt[0][l];
                    now+=d[l][j]*cnt[1][l];
                    now+=d[l][k]*cnt[2][l];
                }
                ans=min(ans,now);
            }
        }
    }
    cout <<ans <<endl;
    return 0;
}