#include<bits//stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
bool isPrime(int x) {
    int i;
    if (x < 2)return 0;
    else if (x == 2) return 1;
    if (x % 2 == 0) return 0;
    for (i = 3; i * i <= x; i += 2) if (x % i == 0) return 0;
    return 1;
}
int main() {
	int q, l, r;int k[100001];cin >> q;k[1] = 0;
	for (int i = 3;i < 100001;i += 2) {
        k[i] = k[i - 2];
        int o = (i + 1) / 2;
        if (isPrime(i) && isPrime(o)) k[i]++;
	}
    for (int i = 0; i < q;i++) {
        cin >> l >> r;
        if (l != 1) cout << k[r] - k[l - 2] << endl;
        else cout << k[r] << endl;
    }
}