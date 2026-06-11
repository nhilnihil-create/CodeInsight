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
    vector<vector<int>> PYN(M, vector<int>(3));
    for(int i = 0; i < M; i++){
        cin >> PYN[i][0] >> PYN[i][1];
        PYN[i][2] = i + 1;
    }
    sort(all(PYN));
    vector<int> X(M);
    X[0] = 1;
    int x = 1;
    for(int i = 1; i < M; i++){
        if(PYN[i - 1][0] != PYN[i][0]) x = 1;
        else x++;
        X[i] = x;
    }
    vector<vector<int>> NPX(M, vector<int>(3));
    for(int i = 0; i < M; i++){
        NPX[i][0] = PYN[i][2];
        NPX[i][1] = PYN[i][0];
        NPX[i][2] = X[i];
    }
    sort(all(NPX));
    for(auto v : NPX){
        printf("%06d", v[1]);
        printf("%06d\n", v[2]);
    }
}