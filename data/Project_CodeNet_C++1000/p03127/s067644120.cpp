#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
vector <ll> a(100002);
int main() {
    int N , T;
	cin >> N;
	cin >> T;
	for(int i = 1; i < N; i++) {
        int a;
        cin >> a;
		T = gcd(a , T);
	}
	cout << T << endl;;
}