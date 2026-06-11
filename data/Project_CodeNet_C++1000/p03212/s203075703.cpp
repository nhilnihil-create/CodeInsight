//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;




int main() {
    int n;
    cin >> n;
    int ans = 0;
    for(int i=3; i <10; ++i) {
        
        vi vec(i);
        
        rep(j, i-1) {
            rep(k, j) {
                string S;
                rep(h, i) {
                    if(h > j) {
                        S += '7';
                    } else if(h > k) {
                        S += '5';
                    } else {
                        S += '3';
                    }
                }

                do {
                    if(n >= stoi(S)) {
                        ans++;
                    }
                } while(next_permutation(S.begin(), S.end()));
            }
        }
        
    }

    cout << ans << endl;
}