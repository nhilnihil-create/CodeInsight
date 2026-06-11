#include"bits/stdc++.h"
using namespace std;
#define REP(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))
using ll = long long;
constexpr ll MOD = 1e9 + 7;
int main()
{
    ll N;
    string s;
    cin >> N >> s;
    map<ll, ll> mp;
    for (char c : s)mp[c]++;
    ll res = 1;
    for (auto itr : mp)(res *= itr.second + 1) %= MOD;
    cout << res - 1 << endl;
    return 0;
}
