#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;

int main()
{
    string s;
    cin >> s;
    int ans = INF;
    int digit;
    rep(i, 0, s.size()-2){
        digit = 100;
        int x = 0;
        rep(j, i, i+3){
            x += (s[j] - '0')*digit;
            digit /= 10;
            //cout << digit << " ";
        }
        ans = min(ans, abs(x - 753));
    }
    cout << ans << endl;
    return 0;
}
