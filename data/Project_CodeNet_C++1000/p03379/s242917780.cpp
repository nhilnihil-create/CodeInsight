#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int n;
    cin >> n;
    vector<P> X(n);
    rep(i, n) {
        cin >> X[i].first;
        X[i].second = i;
    }
    sort(ALL(X));
    int m = n / 2;
    vector<P> A = X;
    rep(i, n) {
        if(i < m) A[i].first = X[m].first;
        else A[i].first = X[m - 1].first;
    }
    vector<int> B(n);
    rep(i, n) {
        B[A[i].second] = A[i].first;
    }
    rep(i, n) cout << B[i] << endl;

    return 0;
}