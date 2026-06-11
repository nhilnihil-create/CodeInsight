#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    int ans = 0;
    queue<ll> q;
    q.push(3);
    q.push(5);
    q.push(7);

    while(!q.empty())
    {
        ll num = q.front(); q.pop();
        if(num <= N)
        {
            string s = to_string(num);
            vector<int> cnt(10, 0);
            for(auto c : s)
            {
                cnt[c- '0']++;
            }
            if(cnt[3]>0 && cnt[5]>0 && cnt[7]>0) ans++;
        }
        if(num*10 + 3 <= N) q.push(num*10 + 3);
        if(num*10 + 5 <= N) q.push(num*10 + 5);
        if(num*10 + 7 <= N) q.push(num*10 + 7);
    }
    cout << ans << endl;
    
    return 0;
}
