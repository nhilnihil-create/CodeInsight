#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<string, string>;
ll MOD = 1e9+7;
int main()
{
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<set<int>> d(n);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        d[a].insert(b);
        d[b].insert(a);
    }
    set<int> remove;
    vector<int> ca(n);
    vector<int> cb(n);
    for(int i = 0; i < n; i++)
    {
        for(int next : d[i])
        {
            if(s[next] == 'A') ca[i]++;
            else cb[i]++;
        }
        if(ca[i] == 0 || cb[i] == 0) remove.insert(i);
    }
    int ans = n;
    while(remove.size())
    {
        int cand = *remove.begin();
        remove.erase(cand);
        ans--;
        for(int next : d[cand])
        {
            if(next == cand) continue;
            d[next].erase(cand);
            if(s[cand] == 'A') ca[next]--;
            else cb[next]--;
            if(ca[next] == 0 || cb[next] == 0)
            {
                remove.insert(next);
            }
        }
    }
    if(ans > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}

