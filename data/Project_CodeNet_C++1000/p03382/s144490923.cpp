#include <bits/stdc++.h>
using namespace std;
using lint = int64_t;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define all(v)    begin(v), end(v)
#define in        []{lint n; cin>>n; return n;}()

int main(){ cin.tie(0); ios::sync_with_stdio(false);
    int N = in;
    vector<int> A(N);
    rep( i, N ) A[i] = in;
    int M = INT_MIN;
    rep( i, N ) M = max( M, A[i] );
    int R = INT_MIN;
    rep( i, N ) if( A[i] != M && abs(M/2-A[i]) < abs(M/2-R) ) R = A[i];
    cout << M << " " << R << "\n";
}
