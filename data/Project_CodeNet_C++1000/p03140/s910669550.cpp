#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    string A, B, C; cin >> A >> B >> C;
    
    int res = 0;
    for(int i=0; i<N; ++i) {
        if(A[i] != B[i] && B[i] != C[i] && C[i] != A[i]) res += 2;
        else if((A[i] == B[i] && B[i] != C[i]) || (B[i] == C[i] && C[i] != A[i]) || (C[i] == A[i] && A[i] != B[i])) res += 1;
    }
    cout << res << endl;
}