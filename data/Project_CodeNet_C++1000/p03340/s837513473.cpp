#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<int> A(N+1);
    for(int i=1; i<=N; i++) {
        cin >> A[i];
    }

    vector< vector<int> > psum(20, vector<int>(N+1));
    for(int i=1; i<=N; i++) {
        for(int bit=0; bit<20; bit++) {
            if((A[i]>>bit) & 1) {
                psum[bit][i] = psum[bit][i-1] + 1;
            } else {
                psum[bit][i] = psum[bit][i-1];
            }
        }
    }

    vector<int> zero(N+2);
    for(int i=N; i; i--) {
        if(A[i] == 0) {
            zero[i] = zero[i+1] + 1;
        }
    }

    int64_t ans = N;
    for(int l=1; l<=N; l++) {
        for(int r=l+1; r<=N; r++) {
            bool ok = true;
            if(A[r] == 0) {
                ans += zero[r];
                r += zero[r] - 1;
            } else {
                for(int bit = 0; bit<20; bit++) {
                    if((psum[bit][r-1]-psum[bit][l-1])%2 > (psum[bit][r]-psum[bit][l-1])%2) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    ans++;
                } else {
                    break;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
