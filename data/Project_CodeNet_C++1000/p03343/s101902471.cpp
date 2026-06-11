#include <bits/stdc++.h>
using namespace std;
int INF = 1e9+7;
int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = INF;
    for(int i = 0; i < n; i++)
    {
        int x = a[i];

        int pos = 0;
        vector<int> al;
        while(pos < n)
        {
            priority_queue<int, vector<int>, greater<int>> que;
            while(pos < n && a[pos] >= x)
            {
                que.push(a[pos]);
                pos++;
            }
            if(que.size() >= k)
            {
                int s = que.size()-k+1;
                while(s)
                {
                    al.push_back(que.top());
                    que.pop();
                    s--;
                }
            }
            pos++;
        }
        if(al.size() < q) continue;
        sort(al.begin(), al.end());
        ans = min(ans, al[q-1] - al[0]);
    }
    cout << ans << endl;
}
