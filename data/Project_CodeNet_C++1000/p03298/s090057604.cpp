#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<string, string> P;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<P, ll> mp;
    for(int b = 0; b < (1 << n); b++){
        string t, u;
        cin >> t >> u;
        for(int i = 0; i < n; i++){
            if((b >> i) & 1) t += s[i];
            else u += s[i];
        }
        mp[P(t, u)]++;
    }
    reverse(s.begin(), s.end());
    ll ans = 0;
    for(int b = 0; b < (1 << n); b++){
        string t, u;
        cin >> t >> u;
        for(int i = 0; i < n; i++){
            if((b >> i) & 1) t += s[i];
            else u += s[i];
        }
        ans += mp[P(t, u)];
    }
    cout << ans << endl;
}
