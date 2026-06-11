#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int N,M;
    cin >> N >> M;
    int ans = 1;
    if(N == 1) {
        cout << M << endl;
    }
    else {
        for(int i = 1; i*i <= M; i++) {
            if(M%i == 0){
                if(i*N <= M) {
                    ans = max(ans,i);
                }
                if(M/i*N <= M) {
                    ans = max(ans,M/i);
                }
            }
        }
        cout << ans << endl;
    }
}
