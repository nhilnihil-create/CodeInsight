#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N, C; cin >> N >> C;
    vector<vector<int>> D(C, vector<int> (C));
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            cin >> D[i][j];
        }
    }

    int tmp;
    vector<vector<int>> c(3);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> tmp;
            tmp--;
            c[(i+j) % 3].push_back(tmp);
        }
    }

    vector<vector<int>> cost(3, vector<int> (C));
    int S;
    for (int i = 0; i < 3; i++) {
        S = c[i].size();
        for (int j = 0; j < C; j++) {
            tmp = 0;
            for (int k = 0; k < S; k++) {
                tmp += D[c[i][k]][j];
            }
            cost[i][j] = tmp;
        }
    }

    int ans = inINF;

    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = 0; k < C; k++) {
                if(i == j || j == k || k == i){
                    continue;
                }
                ans = min(ans, cost[0][i] + cost[1][j] + cost[2][k]);
            }
        }
    }

    printf("%d\n", ans);

}
