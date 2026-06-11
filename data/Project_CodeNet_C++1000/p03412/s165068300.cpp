#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int beki[29];
int N;
int a[200010];
int b[200010];

ll sub(vector<int> A, vector<int> B, int index) {
    B.push_back(-1);
    int border = beki[index];
    ll a_index = 0;
    ll b_index = 0;
    ll ret = 0;
    while(a_index < A.size()) {
        if(A[a_index] + B[b_index] >= border) {
            b_index++;
            continue;
        }
        ret += b_index;
        ret %= 2;
        a_index++;
    }
    return ret;
}

ll solve(int index) {
    vector<int> A[2];
    vector<int> B[2];
    for(int i = 1; i <= N; i++) {
        if((a[i] >> index) & 1) A[1].push_back(a[i] % beki[index]);
        else A[0].push_back(a[i] % beki[index]);
        if((b[i] >> index) & 1) B[1].push_back(b[i] % beki[index]);
        else B[0].push_back(b[i] % beki[index]);
    }
    /*
    cerr << index << endl;
    for(int i = 0; i < A[0].size(); i++) {
        cerr << A[0][i] << " ";
    }
    cerr << endl;
    */
    sort(A[0].begin(), A[0].end());
    sort(A[1].begin(), A[1].end());
    sort(B[0].begin(), B[0].end(), greater<int>());
    sort(B[1].begin(), B[1].end(), greater<int>());
    ll ans = 0;
    ans += sub(A[0], B[0], index);
    ans += sub(A[1], B[1], index);
    ans += (A[0].size() * B[1].size()) - sub(A[0], B[1], index);
    ans += (A[1].size() * B[0].size()) - sub(A[1], B[0], index);
    return ans;
}

int main() {
    //cout.precision(10);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= N; i++) {
        cin >> b[i];
    }
    beki[0] = 1;
    for(int i = 1; i <= 28; i++) {
        beki[i] = beki[i - 1] * 2;
    }
    ll ans = 0;
    for(int i = 0; i <= 28; i++) {
        ll now = solve(i);
        if(now % 2 == 1) ans += beki[i];
    }
    cout << ans << endl;
    return 0;
}
