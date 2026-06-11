#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<string,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> P(m), Y(m);
    rep(i, m) {
        cin >> P[i] >> Y[i];
        P[i]--;
    }
    vector<vector<int>> A(n);
    rep(i, m) {
        A[P[i]].push_back(Y[i]);
    }
    rep(i, n) {
        sort(ALL(A[i]));
    }

    rep(i, m) {
        printf("%06d", P[i] + 1);
        int id = lower_bound(ALL(A[P[i]]), Y[i]) - A[P[i]].begin();
        printf("%06d\n", id + 1);
    }

    return 0;
}