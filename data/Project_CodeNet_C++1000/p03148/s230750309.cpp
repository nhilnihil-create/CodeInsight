#include<bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define fi first
#define se second
#define pb push_back
#define int long long

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 1e5 + 10;
const int oo = 1e18;

int n, k;
vector<ii> vt, type;
set<ii> st, tmp;

bool cmp(const ii &x, const ii &y)    {
    return x.fi > y.fi;
}

signed main()  {
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(false); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n)    {
        int x, y; cin >> x >> y;
        vt.pb({x, y});
    }
    sort(vt.begin(), vt.end());
    for(int i = vt.size() - 1; i >= 0; --i) {
        if(i == vt.size() - 1 || vt[i].fi != vt[i + 1].fi)
            type.pb({vt[i].se, i});
        st.insert({vt[i].se, i});
    }

    int cnt = 0, ans = 0, sum = 0;
    while(k > tmp.size()) {
        auto it = st.end(); it --;
        tmp.insert(*it); sum += (*it).fi;
        st.erase(it);
    }

    sort(type.begin(), type.end(), cmp); ans = sum;

    FOR(i, 1, min(k, (int)type.size()))  {
        auto cur = type[i - 1];
        if(tmp.find(cur) != tmp.end())  {
            tmp.erase(tmp.find(cur));
        } else {
            sum += cur.fi;
            auto id = tmp.begin();
            sum -= (*id).fi;
            tmp.erase(id);
        }

        cnt ++;
        ans = max(ans, sum + cnt * cnt);
    }
    return cout << ans, 0;
}
