#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    double T, X;
    cin >> T >> X;

    double ans = T / X;

    cout << setprecision(10) << ans << endl;

    return 0;
}
