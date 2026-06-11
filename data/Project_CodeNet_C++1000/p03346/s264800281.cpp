#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    int n;
    cin >> n;
    int p[n];
    rep(i, n) {
        int q;
        cin >> q;
        p[q-1] = i;
    }


    int tmp = 1;
    int ans = 0;
    rep(i, n - 1){
        if (p[i] < p[i+1]) tmp++;
        else {
            ans = max(ans, tmp);
            tmp = 1;
        }
    }
    
    ans = max(ans, tmp);
    
    cout << n - ans << endl;

    return 0;
}
