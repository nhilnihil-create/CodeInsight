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
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> E(N, 0), W(N, 0);
    if(S[0] == 'E') E[0] = 1;
    else W[0] = 1;
    for(int i = 1; i < N; i++){
        if(S[i] == 'E') {
            E[i] = E[i - 1] + 1;
            W[i] = W[i - 1];
        }else{
            E[i] = E[i - 1];
            W[i] = W[i - 1] + 1;
        }
    }
    // for(int e : E) cout << e;
    // cout << endl;
    // for(int w : W) cout << w ;
    int min_n = INT_INF;
    for(int i = 0; i < N; i++){
        int left = 0, right = 0;
        if(i == 0) left = 0;
        else{
            left = W[i - 1];
        }
        if(i == N - 1) right = 0;
        else{
            right = E.back() - E[i];
        }
        min_n = min(min_n, left + right);
    }
    cout << min_n << endl;
}