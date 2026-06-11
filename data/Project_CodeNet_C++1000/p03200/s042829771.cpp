#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
const int MOD = 1e9 + 7;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)

int main() {
    string S;
    cin >> S;
    ll ans = 0;
    ll cnt_b = 0;

    for (int i = 0; i < S.size(); i++){
        if (S[i] == 'B') cnt_b += 1;
        if (S[i] == 'W') {
            ans += cnt_b;
        }
        
    }
    cout << ans << endl;
}