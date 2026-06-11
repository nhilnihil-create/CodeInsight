#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
    string n;
    cin >> n;
    int ans = 0;
    bool all9 = true;
    rep(i,n.size()-1) {
        ans += 9;
        if (n[i+1] != '9') all9 = false;
    } 
    ans += n[0] - '0';
    if (!all9) ans--;
    cout << ans << endl; 
    return 0;
}