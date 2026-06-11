#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9+7;

int main() {
    LL N, M;
    cin >> N >> M;
    if(N == 1 || M == 1) {
        if(N*M == 1) {
            cout << 1 << endl;
        }else{
            cout << N*M - 2 << endl;
        }
    }else{
        cout << (N - 2)*(M - 2) << endl;
    }
    return 0;
}
