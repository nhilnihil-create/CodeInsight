#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    cin >> N;
    vector<int> A(N),B(N),C(N);
    rep(i,N) {
        int a;
        cin >> a ;
        A[i] = a;

    }
    rep(i,N) {
        int b;
        cin >> b;
        B[i] = b;
    }
    rep(i,N) {
        int c;
        cin >>c;
        C[i] = c;
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());

    vector<int> X(N),Y(N);
    ll ans = 0;

    rep(i,N) {
        ll idx1 = lower_bound(A.begin(),A.end(),B[i]) - A.begin();
        ll idx2 = upper_bound(C.begin(),C.end(),B[i]) - C.begin();
        idx2 = N-idx2;
        //idx1 = idx-1;
        ans += idx1*idx2; 
        //cout << idx1 << " " << idx2 << endl;

    }
    cout << ans << endl;
}
