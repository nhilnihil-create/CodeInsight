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
    string S, T;
    cin >> S >> T;
    int N = S.size();
    bool ok = false;
    for(int i = 0; i < N; i++){
        if(S == T){
             ok = true;
             break;
        }
        S = S.back() + S.substr(0, N - 1);
        
    }
    if(ok) puts("Yes");
    else puts("No");
}
