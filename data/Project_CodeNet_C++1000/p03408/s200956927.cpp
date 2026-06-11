#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n, m;
    map<string, int> ma;

    cin >> n;
    rep(i, n) {
        string s;
        cin >> s;
        ma[s]++;
    }

    cin >> m;
    rep(i, m) {
        string s;
        cin >> s;
        ma[s]--;
    }

    int ans = 0;
    for (auto a : ma) ans = max(ans, a.second);
    cout << ans << endl;

    return 0;
}