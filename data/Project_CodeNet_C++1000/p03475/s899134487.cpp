//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int N;
    cin >> N;
    vi C(N-1), S(N-1), F(N-1);
    rep(i, N-1) {
        cin >> C[i] >> S[i] >> F[i];
    }
    vi tim;
    rep(i, N-1) {
        tim.push_back(0);
        rep(j, i+1) {
            if(tim[j] <= S[i]) {
                tim[j] = S[i] + C[i];    
            } else { 
                int t;
                t = (tim[j] + F[i] - 1)/F[i];
                tim[j] = F[i] * t;
                tim[j] += C[i];
            }
        }
    }
    rep(i, N-1) {
        cout << tim[i] << '\n';
    }
    cout << 0 << '\n';
}