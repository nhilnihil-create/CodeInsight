#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        string S;
        cin >> S;
        ll ans = 0;
        for (int i = 0; i < 3; ++i) {
                if (S[i] == '1') {
                        ans++;
                }
        }
        cout << ans << endl;


}
