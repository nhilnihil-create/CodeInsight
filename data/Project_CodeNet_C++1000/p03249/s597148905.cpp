#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<ll> d(n);
    using P = pair<ll, ll>;
    vector<P> p(n);
    for(int i = 0; i < n; i++)
    {
        cin >> d[i];
        p[i] = P(d[i], i+1);
    }
    sort(d.begin(), d.end());
    sort(p.begin(), p.end());

    vector<int> num(n);
  vector<P> ans;
    vector<ll> dis(n);
    for(int i = n-1; i >= 1; i--)
    {
        num[i]++;
        ll cand = d[i] - n + 2 * num[i];
        int x = lower_bound(d.begin(), d.end(), cand) - d.begin();
        if(x >= i || d[x] != cand)
        {
            cout << -1 << endl;
            return 0;
        }
        num[x] += num[i];
        dis[x] = dis[x] + dis[i] + num[i];
        ans.push_back(P(x, i));
    }
    if(dis[0] != d[0])
    {
      cout << -1 << endl;
      return 0;
    }
    for(int i = 0; i < ans.size(); i++)
    {
        cout << p[ans[i].first].second << " " << p[ans[i].second].second << endl;
    }
}
