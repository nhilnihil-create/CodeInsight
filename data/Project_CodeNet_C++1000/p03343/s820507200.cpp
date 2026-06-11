#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, K, q;
    cin >> n >> K >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll fans = 1e10;
    for(int i = 0; i < n; i++)
    {
        ll delim = a[i];
        vector<ll> ans;
        int j = 0;
        while(j < n)
        {
            vector<ll> tmp;
            int k;
            for(k = j; k < n; k++)
            {
                if(a[k] >= delim)
                {
                    tmp.push_back(a[k]);
                }
                else
                {
                    k++;
                    break;
                }
            }
            j = k;
            int size = tmp.size();
            sort(tmp.begin(), tmp.end());
            for(int m = 0; m <= size - K && m < q; m++)
            {
                ans.push_back(tmp[m]);
            }
        }
        sort(ans.begin(), ans.end());
        if(ans.size() >= q)
        {
            fans = min(fans, ans[q-1] - ans[0]);
        }
    }
    cout << fans << endl;
}

