#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i,N){
        cin >> A[i];
    }
    vector<int> cost(N+1),cost2(N),cost3(N);
    ll all = 0;
    REP(i,N+1){
        if ( i == 0 ) {
            cost[0] = abs(A[0]);
        } else if ( i == N ) {
            cost[N] = abs(A[N-1]);
        } else {
            cost[i] = abs(A[i]-A[i-1]);
        }
        all += cost[i];
    }
    REP(i,N){
        if ( i == 0 ){
            cost2[0] = abs(A[1]);
        } else if ( i == N-1 ){
            cost2[N-1] = abs(A[N-2]);
        } else {
            cost2[i] = abs(A[i+1] - A[i-1]);
        }
    }
    REP(i,N){
        cost3[i] = cost[i] + cost[i+1];
    }
    
    ll ans;
    REP(i,N){
        ans = all - cost3[i] + cost2[i];
        cout << ans << endl;
    }
    
    
    
    return 0;
}
