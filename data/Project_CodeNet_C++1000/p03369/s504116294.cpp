#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
    string s;
    cin >> s;
    ll ans = 700;
    if (s[0] == 'o') ans += 100;
    if (s[1] == 'o') ans += 100;
    if (s[2] == 'o') ans += 100;
    cout << ans << endl;



}
