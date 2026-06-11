#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N; cin >> N;
    string s;
    map<char, ll> S;
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s.at(0) == 'M') {
            if (!S.count('M')) S['M'] = 1;
            else S['M']++;
        }
        else if (s.at(0) == 'A') {
            if (!S.count('A')) S['A'] = 1;
            else S['A']++;
        }
        else if (s.at(0) == 'R') {
            if (!S.count('R')) S['R'] = 1;
            else S['R']++;
        }
        else if (s.at(0) == 'C') {
            if (!S.count('C')) S['C'] = 1;
            else S['C']++;
        }
        else if (s.at(0) == 'H') {
            if (!S.count('H')) S['H'] = 1;
            else S['H']++;
        }
    }
    ll m = S['M'], a = S['A'], r = S['R'], c = S['C'], h = S['H'];
    ll ans = m * (a * (r + c + h) + r * (c + h) + c * h) + a * (r * (c + h) + c * h) + r * c * h;
    cout << ans << endl;
    return 0;
}