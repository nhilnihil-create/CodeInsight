#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;cin>>n>>m;
    vector<vector<int>> g(n);
    vector<int> live(n,1), acnt(n,0), bcnt(n,0);
    string s;
    cin>>s;
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
        if(s[a]=='A')
        {
            acnt[b]++;
        }
        else
        {
            bcnt[b]++;
        }
        if(s[b]=='A')
        {
            acnt[a]++;
        }
        else
        {
            bcnt[a]++;
        }
    }
    queue<int> que;
    for(int i=0;i<n;i++)
    {
        if(acnt[i]==0 || bcnt[i]==0)
        {
            que.push(i);
            live[i] = 0;
        }
    }
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        for(auto v:g[cur])
        {
            if(live[v]==0) continue;
            if(s[cur]=='A')
            {
                acnt[v]--;
            }
            else
            {
                bcnt[v]--;
            }
            if(acnt[v] && bcnt[v]) continue;
            que.push(v);
            live[v] = 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(live[i])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
