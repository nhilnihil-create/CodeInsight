#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>
#include<cmath>
#include<assert.h>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<complex>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound


signed main() {
    int N;
    cin >> N;
    if (N == 3) {
        cout << "2 5 63" << endl;
        return 0;
    } else if (N == 4) {
        cout << "2 5 20 63" << endl;
        return 0;
    }
    int cnt3 = 0;
    for (int i = 3; i <= 30000; i += 6) {
        cout << i << " ";
        cnt3++;
        if (cnt3 % 2 == 0 && cnt3 + 15000 >= N)break;
    }
    int cnt2 = 0;
    for (int i = 2; i <= 30000; i += 2) {
        if (i % 3 == 0)continue;
        cout << i << " ";
        cnt2++;
        if (cnt2 % 2 == 0 && cnt2 + cnt3 + 5000 >= N)break;
    }
    int cnt6 = 0;
    for (int i = 6; i <= 30000 && cnt2 + cnt3 + cnt6 <= N; i += 6) {
        cout << i;
        cnt6++;
        if (cnt2 + cnt3 + cnt6 < N)cout << " ";
        else {
            cout << endl;
            return 0;
        }
    }
}
