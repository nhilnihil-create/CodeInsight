#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> x(N, vector<int> (N, 0));
    vector<vector<int>> c(N, vector<int> (N+1, 0));
    int tmp1,tmp2;
    for (int i = 0; i < M; i++){
        cin >> tmp1 >> tmp2; tmp1--; tmp2--;
        x[tmp1][tmp2]++;
    }
    for (int i = 0; i < N; i++) {
        c[i][0] = 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N+1; j++) {
            c[i][j] = c[i][j-1] + x[i][j-1];
        }
    }   
    int ans = 0;
    for (int i = 0; i < Q; i++) {
        cin >> tmp1 >> tmp2; tmp1--; tmp2--;
        ans = 0;
        for (int j = tmp1; j <= tmp2; j++) {
            ans += c[j][tmp2+1] - c[j][tmp1];
        }
        printf("%d\n", ans);
    }

    


}
