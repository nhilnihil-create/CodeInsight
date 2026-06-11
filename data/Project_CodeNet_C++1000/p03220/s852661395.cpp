#include <bits/stdc++.h>
using namespace std;

int main() {
    double N,T,A;
    cin >> N >> T >> A;
    vector<double>H(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i];
        H[i] = T-H[i]*0.006;
    }
    double cnt = 1000000;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(abs(A-H[i]) < cnt) {
            ans = i+1;
            cnt = abs(A-H[i]);
        }
    }
    cout << ans << endl;
}