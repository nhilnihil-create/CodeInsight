#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    int maxv = -1;
    int ans = 0;
    rep(i,n) {
        int p;
        cin >> p;
        ans += p;
        maxv = max(maxv, p);
    }

    cout << ans - maxv/2 << endl;    
    return 0;
}