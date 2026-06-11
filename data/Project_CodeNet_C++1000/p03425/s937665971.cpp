#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll N; cin >> N;
        vector<ll> J(5, 0);
        for (int i = 0; i < N; ++i) {
                string s;
                cin >> s;
                if (s[0] == 'M') J[0]++;
                else if (s[0] == 'A') J[1]++;
                else if (s[0] == 'R') J[2]++;
                else if (s[0] == 'C') J[3]++;
                else if (s[0] == 'H') J[4]++;
        }

        ll ans = 0;
        for (int i = 0; i < 3; ++i) {
                for (int j = i+1; j < 4; ++j) {
                        for (int k = j+1; k < 5; ++k) {
                                ans += (J[k] * J[j] * J[i]);
                        }
                }
        }
        cout << ans << endl;



}
