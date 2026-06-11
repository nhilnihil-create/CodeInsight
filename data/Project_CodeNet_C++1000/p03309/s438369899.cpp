#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin >> n;
    vector<int> dim(n, 0);
    vector<int> l(n);
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    for (int i = 0; i < n; i++)
    {
        dim[i] = l[i] - (i + 1);
    }
    sort(dim.begin(), dim.end());
    int mid = dim[n / 2];
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(dim[i] - mid);
    }
    cout <<  ans  << endl;
}