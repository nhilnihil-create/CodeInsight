#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    double T,A;
    cin >> N >> T >> A;
    vector<double>H(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i];
        H[i] = T-H[i]*0.006;
    }
    int ans = 1;
    double cnt = abs(A-H[0]);
    for(int i = 1; i < N; i++) {
        if(cnt > abs(A-H[i])) {
            ans = i+1;
            cnt = abs(A-H[i]);
        }
    }
    cout << ans << endl;
}
