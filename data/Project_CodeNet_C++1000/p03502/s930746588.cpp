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
    int Nini = N;
    int f = 0;
    while ( N > 0 ){
        int x = N % 10, y = N / 10;
        f += x;
        N = y;
    }
    
    bool flg = false;
    if ( Nini % f == 0 ) flg = true;
    
    if ( flg ) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
