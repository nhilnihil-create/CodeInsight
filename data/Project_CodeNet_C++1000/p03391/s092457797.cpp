#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;
const ll INF = 1LL<<60;

int main(){
    int N; cin >> N;
    vector<ll> A(N), B(N), C(N);
    REP(i,N) cin >> A[i] >> B[i];
    REP(i,N) C[i] = min(A[i], B[i]);
    int idx = -1;
    ll m = INF;
    ll s = 0;
    REP(i,N) {
        s += A[i];
        if (A[i]>C[i] && m>B[i]) {
            m = B[i];
            idx = i;
        }
    }
    if(m==INF) {
        cout << 0 << endl;
    }
    else {
        cout << s - C[idx] << endl;
    }
    return 0;
}