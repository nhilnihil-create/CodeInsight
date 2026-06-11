#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    rep(i, n) cin >> a[i];
    

    int ans;
    if ((n-1) % (k-1) == 0) ans = (n-1) / (k-1);
    else ans = (n-1) / (k-1) + 1;
    
    cout <<  ans << endl;
    

    return 0;
}