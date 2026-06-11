#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main()
{
    string s; cin >> s;
    ll now = 0;
    ll ans = 0;
    rep(i, ll(s.size())){
        if (s[i] == 'W'){
            ans += i-now;
            now++;
        }
    }
    cout << ans << endl;

}