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
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int q1_num = 0;
    int q2_num = 0;
    int q3_num = 0;
    rep(i, n) {
        int p;
        cin >> p;
        if ( p <= a ) {
            ++q1_num;
        }
        else if ( p >= a + 1 && p <= b ) {
            ++q2_num;
        }
        else if ( p >= b + 1 ) {
            ++q3_num;
        }
    }
    cout << min({q1_num, q2_num ,q3_num}) << endl;
    return 0;
}
