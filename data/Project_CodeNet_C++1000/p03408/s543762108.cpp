#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n, m;
    cin >> n;
    string s[n];
    rep(i, n) cin >> s[i];
    cin >> m;
    string t[m];
    rep(i, m) cin >> t[i];
    int ans = 0;
    rep(i, n) {
        int cou = 0;
        rep(j, n) {
            if(s[i] == s[j]) cou++;
        }
        rep(j, m) {
            if(s[i] == t[j]) cou--;
        }
        ans = max(ans, cou);
    }

    cout << ans << endl;

    return 0;
}