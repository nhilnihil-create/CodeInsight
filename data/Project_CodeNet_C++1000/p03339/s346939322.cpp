#include <iostream>
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define all(x) (x).begin(),(x).end()
#define dump(x) cout << #x << " = " << (x) << endl

using namespace std;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int cnt_w = 0;
    int cnt_e = 0;

    rep(i, n) {
        if (s[i] == 'W') cnt_w++;
        else cnt_e++;
    }

    int ans = INF;
    int change_w = 0;
    int change_e = cnt_e;

    rep(i, n) {
        if (s[i] == 'E') {
            change_e--;
        }
        if (change_e + change_w <= ans) {
            ans = change_e + change_w;
        }
        if (s[i] == 'W') {
            change_w++;
        }
    }

    cout << ans << endl;
}