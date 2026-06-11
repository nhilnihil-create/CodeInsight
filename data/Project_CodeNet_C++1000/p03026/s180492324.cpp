#include <bits/stdc++.h>
using namespace std;
#define all(n) begin(n), end(n)
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts)
{
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v)
{
    for (auto &e : t)
        fill_v(e, v);
}
vint ans;
int pts = 0,idx=0;
vint c;
vvint graph;
void dfs(int cur = 0,int prev = -1)
{
    ans[cur] = c[idx++];
    for (auto &&i : graph[cur])
    {
        if(i != prev)
        {
            dfs(i,cur);
        }
    }
    
    
}
int main()
{
    int N;
    cin>>N;
    graph.resize(N);
    int a,b;
    for (size_t i = 0; i < N-1; i++)
    {
        cin>>a>>b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    c.resize(N);
    for (size_t i = 0; i < N; i++)
    {
        cin>>c[i];
    }
    sort(all(c),greater<int>());
    ans.resize(N);
    dfs();
    cout<<accumulate(all(c),0LL) - c[0]<<endl;
    for (auto &&i : ans)
    {
        cout<<i<<" ";
    }
    
    return 0;
}
