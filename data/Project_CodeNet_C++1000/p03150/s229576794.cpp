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
    string s;
    cin >> s;
    int n = s.size();
    bool f = 0;

    rep(i, n-1){
        for(int j = i; j < n; j++){
            if (s.substr(0, i) + s.substr(j, n-j) == "keyence") f = 1;
        }
    }

    if (f) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
