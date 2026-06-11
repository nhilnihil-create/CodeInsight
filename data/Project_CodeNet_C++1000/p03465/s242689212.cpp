#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

int main() {
    int N; cin >> N;
    vector<int> A(N);
    int s=0;
    REP(i,N) {
        cin >> A[i];
        s += A[i];
    }
    vector<bitset<2000001>> v(N+1);
    v[0].set(0);
    REP(i,N) {
        v[i+1] = (v[i]<<A[i]);
        v[i+1] |= v[i];
    }
    int ans = 0;
    REP(i,s/2+1) {
        if(v[N][i]) ans = s - i;
    }
    cout << ans << endl;
}