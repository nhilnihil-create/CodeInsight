#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

int main() {
    int N; cin >> N;
    vector<int> A(N);
    bitset<2000001> b;
    b.set(0);
    int s=0;
    REP(i,N) {
        int a;
        cin >> a;
        s += a;
        b |= (b<<a);
    }
    int ans = 0;
    REP(i,s/2+1) {
        if(b[i]) ans = s - i;
    }
    cout << ans << endl;
}