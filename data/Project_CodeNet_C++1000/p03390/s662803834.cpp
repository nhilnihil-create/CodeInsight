#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#define INF 1e9
#define MAX_Q 101

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main() {
    int Q;
    ll A[MAX_Q], B[MAX_Q];
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        cin >> A[i] >> B[i];
    }
    
    for (int i = 0; i < Q; ++i) {
        ll ans = 0;
        ll mul = A[i] * B[i];
        ll m = (ll)sqrt((double)mul);
        if (m * m == mul) {
            --m;
        }
        // m: sqrt(mul)より真に小さい整数
        
        if (m * (m + 1) < mul) {
            ans = 2 * m;
        } else {
            ans = 2 * m - 1;
        }
        
        if (m >= A[i]) {
            --ans;
        }
        if (m >= B[i]) {
            --ans;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
