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
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];
    int M;
    cin >> M;
    vector<string> T(M);
    for(int i = 0; i < M; i++) cin >> T[i];

    map<string, int> S1;
    map<string, int> T1;
    for(string s: S) S1[s]++;
    for(string t: T) T1[t]++;
    int max_n = 0;
    for(auto p : S1){
        max_n = max(max_n, p.se - T1[p.fi]);
    }
    cout << max_n << endl;
}
