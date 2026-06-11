#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
    int N;
    cin >> N;
    int M = 100;
    vector<ll> L(M,0);
    
    L[0] = 2LL; L[1] = 1LL;
    for ( int i = 2; i < M; ++i){
        L[i] = L[i-1] + L[i-2];
    }
    cout << L[N] << endl;
    
    
    return 0;
}