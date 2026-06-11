#include <bits/stdc++.h>

#define fr first
#define sc second
#define pb push_back
#define mk make_pair
#define ll long long
#define OK puts("OK")
#define sz(s) (int)s.size()
#define all(s) s.begin(), s.end()

using namespace std;

const int N = 2e5+10;
const int inf = 1e9+7;

ll n, m, ans = 0;
ll x[N], y[N], s[N], p[N];
set <pair <ll, int> > st;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        p[i] = p[i - 1] + y[i];
    }
    for(int i = n; i >= 1; i--) {
        s[i] = s[i + 1] + y[i];
        st.insert(mk(-(s[i] - m + x[i]), i));
    }
    for(int i = 1; i <= n; i++) {
        st.erase(mk(-(s[i] - m + x[i]), i));
        ans = max(ans, p[i] - x[i]);
        if(!st.empty())
            ans = max(ans, p[i] - x[i] - x[i] - st.begin()->fr);
    }
    for(int i = 1; i <= n; i++) {
        st.insert(mk(-(p[i] - x[i]), i));
    }
    for(int i = n; i >= 1; i--) {
        st.erase(mk(-(p[i] - x[i]), i));
        ans = max(ans, s[i] - m + x[i]);
        if(!st.empty())
            ans = max(ans, s[i] - m + x[i] - m + x[i] - st.begin()->fr);
    }
    cout << ans << endl;
}
