#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int N;
int t[110], v[110];
int lim[50010];
 
long long int dp[5][205];
 
int main() {
    while (cin >> N) {
        for (int i = 0; i < N; ++i) 
          cin >> t[i], t[i] *= 2;
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            cin >> v[i], v[i] *= 2;
            for (int j = ans; j < ans + t[i]; ++j) {
                lim[j] = v[i];
            }
            ans += t[i];
        }
        
        for (int i = 0; i < 5; ++i){
          for (int j = 0; j < 205; ++j){
            dp[i][j] = -1e27;
          }
        }
      
        dp[0][0] = 0;
        for (int i = 0; i < ans; ++i) {
          
            for (int j = 0; j < 205; ++j) {
                
                if (j + 1 <= min(lim[i], lim[i+1])) {
                  chmax(dp[(i+1)%2][j+1], dp[i%2][j] + j*2+1);
                }
              
                if (j <= min(lim[i], lim[i+1])){
                  chmax(dp[(i+1)%2][j], dp[i%2][j] + j*2);
                }
              
                if (j - 1 >= 0 && j - 1 <= min(lim[i], lim[i+1])){
                  chmax(dp[(i+1)%2][j-1], dp[i%2][j] + j*2-1);
                }
            }
            
            for (int j = 0; j < 205; ++j) dp[i%2][j] = -1e27;
          
        }
        
       printf("%.10lf\n",(double)dp[0][0]*0.125);
    }
}
 
 
 
