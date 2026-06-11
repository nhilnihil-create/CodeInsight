#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second

int main(){
    int N;
    cin >> N;
    vector<string> W(N);
    for(int i = 0; i < N; i++) cin >> W[i];
    bool ok = true;
    for(int i = 0; i < N - 1; i++){
        if(W[i][W[i].size()-1] != W[i + 1][0]) ok = false;
    }
    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            if(W[i] == W[j]) ok = false;
        }
    }
    if(ok) puts("Yes");
    else puts("No");
}
