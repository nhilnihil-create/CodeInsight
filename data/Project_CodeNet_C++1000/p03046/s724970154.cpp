#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {

    int M, K;
    cin >> M >> K;
    int len = 1;
    rep(i,M) len *= 2;
    if (M <= 1 && K > 0 || len <= K) {
        cout << -1 << endl;
        return 0;
    } else if (M == 0) {
        printf("0 0\n");
        return 0;
    } else if (M == 1) {
        printf("0 0 1 1\n");
        return 0;
    }

    rep(i,len) {
        if (i != K) cout << i << " ";
    }
    cout << K << " ";
    for (int i = len - 1; i >= 0; i--) {
        if (i != K) cout << i << " ";
    }
    cout << K << endl;
    
    return 0;
}