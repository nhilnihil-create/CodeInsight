#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define INF 10e7
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;

void solve(void)
{
    int n;
    cin >> n;
    set<char> st;
    rep(i, n)
    {
        char tmp;
        cin >> tmp;
        st.insert(tmp);
    }
    map<int, string> mp;
    mp[3] = "Three", mp[4] = "Four";
    cout << mp[st.size()] << endl;
}
int main(void)
{
    solve();
}