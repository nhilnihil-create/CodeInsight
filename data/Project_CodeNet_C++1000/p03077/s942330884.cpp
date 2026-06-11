#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,A,B,C,D,E;
    cin >> N >> A >> B >> C >> D >> E;
    int X = N/min(min(min(min(A,B),C),D),E);
    if(N%min(min(min(min(A,B),C),D),E) == 0) {
        X--;
    }
    cout << 5+X << endl;
}
