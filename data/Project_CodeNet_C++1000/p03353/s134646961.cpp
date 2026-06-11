#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define INF LLONG_MAX
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    string s; cin >> s;
    ll k; cin >> k;
    set<string> st;
    for (int size = 1; size <= k; size++)
    {
        for (int i = 0; i < s.size() - size + 1; i++) {
            st.insert(s.substr(i, size));
        }
    }

    // for (auto elem : st) cout << elem << " "; cout << endl;

    vector<string> ks(st.begin(), st.end());
    // for (auto elem : ks) cout << elem << " "; cout << endl;

    cout << ks[k-1] << endl;
    return 0;
}