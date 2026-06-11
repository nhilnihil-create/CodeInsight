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

int N;
int A[100100];
vector<pii> candidates;

signed main() {
    cin >> N;
    rep(i, N) {
        cin >> A[i];
    }
    sort(A, A + N);
    rep(i, N) {
        int x = A[i];
        int y1 = *l_b(A, A + N, x / 2);
        int y2 = *(l_b(A, A + N, x / 2) - 1);
        int y;
        if (x == y1)y = y2;
        else if (x == y2)y = y1;
        else if (y1 - 1. * x / 2 <= 1. * x / 2 - y2)y = y1;
        else y = y2;
        candidates.emplace_back(x, y);
    }
    sort(candidates.begin(), candidates.end());
    cout << candidates[candidates.size() - 1].first << " " << candidates[candidates.size() - 1].second << endl;
    return 0;
}
