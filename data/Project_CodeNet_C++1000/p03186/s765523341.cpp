#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b, c;
    cin >> a >> b >> c;

    cout << min(b + a + 1, c) + b;

    
 
    return 0;
}