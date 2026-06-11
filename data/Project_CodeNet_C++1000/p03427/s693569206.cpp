#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N , ans = 0;
    cin >> N;
    N++;
    while(N >= 10){
		ans += 9;
		N /= 10;
	}
    ans += N - 1;
    cout << ans << endl;
    return 0;
}
