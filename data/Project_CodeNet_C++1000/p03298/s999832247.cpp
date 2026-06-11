#include <iostream>
#include <utility>
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
    map<P, int> mp;
    for(int i = 0; i < (1 << n); i++){
        string r = "";
        string b = "";
        for(int j = 0; j < n; j++){
            if(i & (1 << j)) r += s[n * 2 - 1 - j];
            else b += s[n * 2 - 1 - j];
        }
        mp[P(r, b)]++;
    }
    ll ans = 0;
    for(int i = 0; i < (1 << n); i++){
        string r = "";
        string b = "";
        for(int j = 0; j < n; j++){
            if(i & (1 << j)) r += s[j];
            else b += s[j];
        }
        ans += mp[P(r, b)];
    }
    cout << ans << endl;
}