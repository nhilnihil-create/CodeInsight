#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(all(a));
    rep(i, n) {
        if(x < a[i]) {
            cout << i << endl;
            return 0;
        }
        x -= a[i];
    }

    if(x) cout << n-1 << endl;
    else cout << n << endl;

    return 0;
}