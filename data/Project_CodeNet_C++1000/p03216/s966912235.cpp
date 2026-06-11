#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; string S; int Q;
    cin >> N >> S >> Q;

    while(Q--) {
        int k; cin >> k;
        long long d = 0, m = 0, dm = 0, res = 0;
        for(int i=0; i<N; ++i) {
            if(i - k >= 0) {
                if(S[i - k] == 'D') d -= 1, dm -= m;
                if(S[i - k] == 'M') m -= 1;
            }
            if(S[i] == 'D') d += 1;
            if(S[i] == 'M') dm += d, m += 1;
            if(S[i] == 'C') res += dm; 
        }
        cout << res << '\n';
    }
}