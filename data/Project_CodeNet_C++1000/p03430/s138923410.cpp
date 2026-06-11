#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int best[310][310][310];

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    for(int i = n-1; i >= 0; i--){
        for(int a = 0; a <= k; a++){
            if(i > 0) best[i][i-1][a] = 0;
        }
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = i; j < n; j++){
            for(int a = 0; a <= k; a++){
                best[i][j][a] = 1;
                if(i == j) continue;
                best[i][j][a] = max(best[i][j][a], best[i+1][j][a]);
                best[i][j][a] = max(best[i][j][a], best[i][j-1][a]);
                if(s[i] == s[j]){
                    best[i][j][a] = max(best[i][j][a], 2 + best[i+1][j-1][a]);
                } else {
                    if(a > 0){
                        best[i][j][a] = max(best[i][j][a], best[i+1][j-1][a-1] + 2);
                    }
                }
            }
        }
    }
    
    
    cout << best[0][n-1][k] << endl;
}
