/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.20 04:22:18
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int keta(int x) {
    int ret = 0;
    while(x) {
        ret++;
        x >>= 1;
    }
    return ret;
}
int bitpopcount(ll n) {
    int res = 0;
    while (n) {
        if (n & 1) res++;
        n >>= 1;
    }
    return res;
}
int main() {
    int l;cin >> l;
    int n = keta(l);
    int m = (n - 1) * 2 + bitpopcount(l) - 1;
    cout << n << " " << m << endl;
    int two = 1, r = l;
    for (int i = n-2; i >= 0; i--) {
        cout << i + 1 << " " << i + 2 << " " << 0 << endl;
        cout << i + 1 << " " << i + 2 << " " << two << endl;
        if (l & (1 << (n-2-i))) {
            cout << 1 << " " << i + 2 << " " << r - two << endl;
            r -= two;
        }
        two <<= 1;
    }
    return 0;
}