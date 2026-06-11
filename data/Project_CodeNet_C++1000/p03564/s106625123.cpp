#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)

int main() {
	int N, K;
	cin >> N >> K;
	int a=1;
    rep(i, N) {
        if (a < K) a *= 2;
        else a += K;
    }
    cout << a << endl;
}
