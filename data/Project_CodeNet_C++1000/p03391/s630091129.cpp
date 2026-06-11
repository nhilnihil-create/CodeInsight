#include <bits/stdc++.h>
using namespace std;
int INF = 1e9+7;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    int count = 0;
    int bmin = 1e9+1;
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        sum += a[i];
        if(a[i] > b[i])
        {
            count++;
            bmin = min(bmin, b[i]);
        }
    }
    if(count == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << sum - bmin << endl;
    }
}
