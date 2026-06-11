#include <bits/stdc++.h>
#define rep(i, z, n) for(int64_t i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
#define PI 3.14159265358979
//const int64_t INF = 1LL << 60;
//const int INF = 1 << 29;
//const int MODINF = 1000000007;
//const int64_t INF = 998244353;
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    if (A >= 13) cout << B << endl;
    else if (A >= 6) cout << B / 2 << endl;
    else cout << 0 << endl;
}