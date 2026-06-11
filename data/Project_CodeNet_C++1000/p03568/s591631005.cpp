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
    ll tmp = 1;
    rep(i, n){
        int a;
        cin >> a;
        if (a%2==0) tmp*=2;
    }
    cout << ll(pow(3,n)) - tmp << endl;

    return 0;
}
