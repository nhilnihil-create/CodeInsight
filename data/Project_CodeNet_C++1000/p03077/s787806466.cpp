#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;



int main(){
    ll N, A, B, C, D, E; cin >> N >> A >> B >> C >> D >> E;
    ll Min = min(A, min(B, min(C, min(D, E))));
    int parity = 0;
    if(N % Min != 0) parity = 1;
    cout << N / Min + parity + 4 << endl;


}