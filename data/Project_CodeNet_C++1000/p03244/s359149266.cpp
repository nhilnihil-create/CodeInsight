#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> v(N);
    vector<vector<int64_t>> a(1e+5+1,vector<int64_t>(2,0)),b(1e+5+1,vector<int64_t>(2,0));
    for ( int64_t i = 0; i < N; ++i){
        cin >> v[i];
        if ( i % 2 == 0 ){
            a[v[i]][0] = a[v[i]][0] + 1;
            a[v[i]][1] = v[i];
        } else {
            b[v[i]][0] = b[v[i]][0] + 1;
            b[v[i]][1] = v[i];
        }
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    
    int64_t amaxnum = a[0][0], amax = a[0][1];
    int64_t amaxnum2 = a[1][0];
    int64_t bmaxnum = b[0][0], bmax = b[0][1];
    int64_t bmaxnum2 = b[1][0];
    
    int64_t ans = 0;
    if ( amax != bmax ){
        ans = N - amaxnum - bmaxnum;
    } else {
        ans = min(N - amaxnum2 - bmaxnum, N - amaxnum - bmaxnum2);
    }
    
    cout << ans << endl;
    
    
    return 0;
}
