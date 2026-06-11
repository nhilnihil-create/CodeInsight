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
    ll n, m;
    cin >> n >> m;
    VP p(n);
    rep(i, 0, n) cin >> p[i].first >> p[i].second;
    sort(ALL(p));
    ll i  = 0, ans = 0;
    while(m > 0){
        if(m - p[i].second > 0){
            m -= p[i].second;
            ans += p[i].first * p[i].second;
        }else{
            ans += m * p[i].first;
            m = 0;
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}