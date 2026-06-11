#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i, n) cin >> d[i];

    sort(all(d));
    int now = 0, ans = 0;
    rep(i, n) {
        if(d[i] > now) {
            ans++;
            now = d[i];
        }
    }

    cout << ans << endl;

    return 0;
}