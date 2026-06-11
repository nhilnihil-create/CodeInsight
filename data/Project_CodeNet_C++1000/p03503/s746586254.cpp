#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> F(N,vector<int>(10));
    for (int i=0;i<N;i++){
        for (int j=0;j<10;j++){
            cin >> F[i][j];
        }
    }
    vector<vector<int>> P(N,vector<int>(11));
    for (int i=0;i<N;i++){
        for (int j=0;j<11;j++){
            cin >> P[i][j];
        }
    }
    int ans = -INF;
    for (int i=1;i<(1<<10);i++){
        vector<int> bits(10);
        for (int bit=0;bit<10;bit++){
            if ((i>>bit)&1) bits[bit] = 1;
        }
        int profit = 0;
        for (int j=0;j<N;j++){
            int num = 0;
            for (int k=0;k<10;k++){
                if (bits[k] && F[j][k]){
                    num++;
                } 
            }
            profit += P[j][num];
        }
        ans = max(ans, profit);
    }
    cout << ans << "\n";
}