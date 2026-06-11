#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<numeric>
#include<math.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int a1, a2, a3, b1, b2, b3;
    vector<int> town(5);
    cin >> a1 >> b1;
    ++town[a1], ++town[b1];
    cin >> a2 >> b2;
    ++town[a2], ++town[b2];
    cin >> a3 >> b3;
    ++town[a3], ++town[b3];
    bool ok = true;
    rep(i, 5) {
        if ( town[i] >= 3 ) {
            ok = false;
            break;
        }
    }
    if ( ok ) cout << "YES" << endl;
    else      cout << "NO" << endl;
    return 0;
}
