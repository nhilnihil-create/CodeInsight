#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

void solve();

int main(void){
    int N; cin >> N;
    string S[N]; rep(i, N) cin >> S[i];
    int ans = 0;
    /*
    for(int A = 0; A < N; A++){
        for(int B = 0; B < N; B++){
            bool ok = true;
            for(int j = 0; j < N; j++){
                int r = (j+B-A) % N, c = (A-B) % N;
                if(r < 0) r += N; if(c < 0) c += N;
                if(S[0][j] != S[r][c]){
                    ok = false;
                    //cout << A << " " <<  B  << " " << j << endl;
                }
            }
            if(ok) ans++;
        }
    }
    */
   for(int B = 0; B < N; B++){
       bool ok = true;
       for(int i = 0; i < N; i++){
           for(int j = 0; j < N; j++){
               int r = (j+B) % N, c = (i-B) % N;
               if(r < 0) r+=N; if(c < 0) c+=N;
               if(S[i][j] != S[r][c]) ok = false;
           }
       }
       if(ok) ans++;
   }
    cout << ans*N << endl;
    return 0;
}

void solve(){}