#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;

    ll x = 100 * (N - M) + 1900 * M;

    cout << pow(2, M) * x << endl;
}