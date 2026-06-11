#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    if(n == 1) cout << abs(a[0]-y) << endl;
    else cout << max(abs(a[n-1]-a[n-2]), abs(a[n-1]-y)) << endl;
    return 0;
}