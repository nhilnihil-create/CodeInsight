#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() 
{
    int a, b, k;
    cin >> a >> b >> k;
    int ans = 0;
    int cnt = 0;
    for (int i=min(a,b); i >= 1; i--) {
        if (a%i == 0 && b%i == 0) {
            ans = i;
            cnt++;
        }
        if (cnt == k) break;
    }
    cout << ans << endl;
    return 0;
}
