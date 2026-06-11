#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    int ans = 0;
    int N, H, W;
    cin >> N >> H >> W;
    while(N--) {
        int A, B;
        cin >> A >> B;
        if(A >= H && B >= W) ans++;
    }
    cout << ans << endl;
    return 0;
}
