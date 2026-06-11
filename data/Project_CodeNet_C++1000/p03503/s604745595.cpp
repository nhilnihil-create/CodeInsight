#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main(){
    int n; cin >> n;
    vector<vector<int>> F(n, vector<int>(10)), P(n, vector<int>(11));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            cin >> F[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 11; j++){
            cin >> P[i][j];
        }
    }
    int ans = -INF;
    for(int i = 1; i < (1<<10); i++){
        vector<int> num(n);
        int tmp = 0;
        for(int j = 0; j < 10; j++){
            if(i & (1 << j)){
                for(int k = 0; k < n; k++){
                    if(F[k][j]) num[k]++;
                }
            }
        }
        for(int j = 0; j < n; j++){
            tmp += P[j][num[j]];
        }
        ans = max(tmp, ans);
    }
    cout << ans << endl;
}