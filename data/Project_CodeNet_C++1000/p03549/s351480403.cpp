#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    int64_t N, M;
    cin >> N >> M;
    int64_t x = M * 1900 + (N - M) * 100;
    int64_t y = pow(2, M);
    int64_t z = x * y;
    cout << z << endl;
}