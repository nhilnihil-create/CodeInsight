#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;
    cin >> N;
    vector<int>C(N+1,0);
    vector<int>S(N+1,0);
    vector<int>F(N+1,1);
    for(int i = 0; i < N-1; i++) {
        int c,s,f;
        cin >> c >> s >> f;
        C[i] = c; S[i] = s; F[i] = f;
    }
    for(int i = 0; i < N; i++) {
        int cnt = S[i]+C[i];
        for(int j = i+1; j < N-1; j++) {
            if(cnt <= S[j]) {
                cnt = S[j]+C[j];
            }
            else {
                if(cnt%F[j] == 0) {
                    cnt+=C[j];
                }
                else {
                    cnt+=F[j]-cnt%F[j]+C[j];
                }
            }
        }
        cout << cnt << endl;
    }
}