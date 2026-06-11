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
    vector<pair<int,int>> LR(M);
    for(int i = 0; i < M; i++) cin >> LR[i].fi >> LR[i].se;
    int right = INT_INF;
    for(auto p : LR) right = min(right, p.se);
    int left = 0;
    for(auto p : LR) left = max(left, p.fi);
    cout << max(0, right - left + 1) << endl;
}