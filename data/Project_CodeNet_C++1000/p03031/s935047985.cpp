#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define MOD7 1000000007
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> K(M);
    vector<vector<int>> S(M);
    for(int i = 0; i < M; i++){
        cin >> K[i];
        for(int j = 0; j < K[i]; j++){
            int s;
            cin >> s;
            S[i].push_back(s);
        }
    }
    vector<int> P(M);
    for(int i = 0; i < M; i++) cin >> P[i];
    int ans = 0;
    for(int bit = 0; bit < (1<<N); bit++){
        bool ok = true;
        for(int i = 0; i < M; i++){
            int count = 0;
            for(int j = 0; j < K[i]; j++){
                if(bit & (1 << S[i][j] - 1)) count++;
            }
            if(count % 2 != P[i]) ok = false;
        }
        if(ok) ans++;
    }
    cout << ans << endl;
}