#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll n;
    cin >> n;
    VP ans;
    if(n % 2 == 1) {
        rep(i, 1, n+1) {
            rep(j, 1, n+1) {
                if(i >= j) continue;
                if(i + j == n) continue;
                ans.push_back({i, j});
            }
        }
    }else{
        rep(i, 1, n+1) {
            rep(j, 1, n+1) {
                if(i >= j) continue;
                if(i + j == n+1) continue;
                ans.push_back({i, j});
            }
        }
    }
    cout << ans.size() << endl;
    for(auto e : ans) cout << e.first << " " << e.second << endl;
    return 0;
}