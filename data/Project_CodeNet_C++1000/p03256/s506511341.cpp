#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define FOR(a, b, c) for(int a = b;a <= c; ++a)
#define pb push_back

const int N = 2e5 + 10;
const int MOD = 1e9 + 7;
const int oo = 1e9;

typedef pair<int, int> ii;

int n, m;
int color[N], cnta[N], cntb[N];
vector<int> vi[N];
bool visit[N];
set<ii> st;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    FOR(i, 1, n) {
        char x; cin >> x;
        color[i] = x - 'A';
    }
    FOR(i, 1, m) {
        int u, v; cin >> u >> v;
        vi[u].pb(v);    vi[v].pb(u);
    }
    FOR(i, 1, n)    {
        cnta[i] = cntb[i] = 0;
        for(int v: vi[i])   {
            if(color[v] == 0) cnta[i] ++;
            else cntb[i]++;
        }
        st.insert(ii(cnta[i] * cntb[i], i));
    }
    while(!st.empty() && st.begin()->fi == 0)  {
        int u = st.begin()->se;
        st.erase(st.begin());
        visit[u] = true;
        for(int v: vi[u])   if(!visit[v])   {
            auto it = st.find(ii(cnta[v] * cntb[v], v));
            st.erase(it);
            if(color[u] == 0) cnta[v] --;
            else cntb[v] --;
            st.insert(ii(cnta[v] * cntb[v], v));
        }
    }
    if(st.size() > 0)cout << "Yes";
    else cout << "No";
}

