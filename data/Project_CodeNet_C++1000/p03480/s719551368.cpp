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
    int tmp = n;
    for(int i = 1; i < n; i++) {
        if (s[i-1] != s[i]) tmp = min(max(i, n-i), tmp);
    }
    cout << tmp << endl;
    return 0;
}
