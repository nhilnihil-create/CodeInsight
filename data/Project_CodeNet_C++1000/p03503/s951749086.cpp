#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

unsigned int
ones32(register unsigned int x)
{
        /* 32-bit recursive reduction using SWAR...
	   but first step is mapping 2-bit values
	   into sum of 2 1-bit values in sneaky way
	*/
        x -= ((x >> 1) & 0x55555555);
        x = (((x >> 2) & 0x33333333) + (x & 0x33333333));
        x = (((x >> 4) + x) & 0x0f0f0f0f);
        x += (x >> 8);
        x += (x >> 16);
        return(x & 0x0000003f);
}

int main() {
    int N;
    cin >> N;
    vector<int> F(N);
    rep(i,N) {
        int b = 0;
        rep(j,10) {
            int bit;
            cin >> bit;
            b = b * 2 + bit;
        }
        F.at(i) = b;
    } 
    int P[N][11];
    int mi = 0;
    rep(i,N) {
        rep(j,11) {
            cin >> P[i][j];
            if (mi > P[i][j]) mi = P[i][j];
        }
    }
    ll ma = -(1LL << 60);
    for (int i = 1; i < 1024; i++) {
        ll p = 0;
        rep(j, N) {
            int CB = F[j] & i;
            uint C = ones32(CB);
            p += P[j][C];
        }
        if (ma < p) ma = p;
    }
    cout << ma << endl;
}
