#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define endl '\n'
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second

using ll = long long;
using P = pair<ll, ll>;

/*追加部分*/



/*main関数*/

int main() {
FASTIO;
    int a, b, c, x; cin >> a >> b >> c >> x;
    int ans = 0;

    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            for(int k = 0; k <= c; k++){
                if(500*i + 100*j + 50*k == x)
                    ans++;
            }
        }
    }
    cout << ans << endl;

return 0;
}