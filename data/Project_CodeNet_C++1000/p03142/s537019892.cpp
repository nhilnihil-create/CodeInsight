#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define allpt(v) (v).begin(), (v).end()
#define allpt_c(v) (v).cbegin(), (v).cend()
#define allpt_r(v) (v).rbegin(), (v).rend()



const int mod = 1e9 + 7;
const string wsp = " ";
const string tb = "\t";
const string rt = "\n";

template <typename T>
void show1dvec(const vector<T> &v)
{
    if (v.size() == 0)
        return;
    int n = v.size() - 1;
    rep(i, n) cout << v[i] << wsp;
    cout << v[n] << rt;
    return;
}

template <typename T>
void show2dvec(const vector<vector<T>> &v)
{
    int n = v.size();
    rep(i, n) show1dvec(v[i]);
}

template <typename T, typename S>
bool myfind(T t, S s)
{
    return find(t.cbegin(), t.cend(), s) != t.cend();
}

vector<int> make_kmp_table(string t)
{
    int lt = t.length();
    VI kmptable(lt, 0);
    kmptable[0] = -1;

    return kmptable;
}

void djkstra(int s, VI &depth, VI &parent, const vector<VI> &connect, VI &indeg)
{
    vector<int> search = {s};
    vector<int> new_search;

    while (!search.empty())
    {
        for (auto i :search)
        {
            for (auto j : connect[i])
            {
                if (depth[j] < 1 + depth[i])
                {
                    indeg[j]--;
                    depth[j] = 1 + depth[i];
                    parent[j] = i + 1;
                    if (indeg[j] == 0)
                        new_search.push_back(j);
                }
            }
        }
        search.clear();
        search = new_search;
        new_search.clear();
    }
}

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    // int n;
    // string s, t;
    // cin >> n >> s;
    // VL dp(n + 1, 0ll);
    // vector<set<int>> callspell(n);
    // dp[0] = 1;
    // rep(i, n)
    // {
    //     cin >> t;
    // }

    // rep(i, n)
    // {
    //     for (int z : callspell[i])
    //     {
    //         dp[i + z - 1] += dp[i - 1];
    //         dp[i + z - 1] %= mod;
    //     }
    // }

    // cout << dp[n] << rt;

    int n, m, a, b, s;
    cin >> n >> m;
    VI parent(n, 0), depth(n, 0), indeg(n, 0);
    vector<VI> connect(n);
    rep(i, n + m - 1)
    {
        cin >> a >> b;
        a--, b--;
        connect[a].push_back(b);
        indeg[b]++;
    }
    rep(i, n) if (indeg[i] == 0) s = i;

    djkstra(s, depth, parent, connect, indeg);

    for (auto z : parent) cout << z << rt;

    return 0;
}
