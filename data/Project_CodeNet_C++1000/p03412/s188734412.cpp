#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

int A[200200], B[200200];
int N;
int ans[30];

signed main() {
    cin >> N;
    rep(i, N) {
        cin >> A[i];
    }
    rep(i, N) {
        cin >> B[i];
    }
    int an = 0;
    for (int k = 29; k >= 0; --k) {
        rep(i, N) {
            A[i] %= 1 << (k + 1);
            B[i] %= 1 << (k + 1);
        }
        sort(B, B + N);
        int T = 1 << k;
        //a_i+b_j=[T,2T),[3T,4T)
        rep(i, N) {
            int a = A[i];
            //b_j=[T-a,2T-a),[3T-a,4T-a)
            ans[k] += l_b(B, B + N, 2 * T - a) - l_b(B, B + N, T - a);
            ans[k] += l_b(B, B + N, 4 * T - a) - l_b(B, B + N, 3 * T - a);
            ans[k] %= 2;
        }
        an = an * 2 + ans[k];
    }
    cout << an << endl;
    return 0;
}
