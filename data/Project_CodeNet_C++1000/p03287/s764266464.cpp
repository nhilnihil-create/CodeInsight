#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;

    vector<ll> A(N);
    map<ll, ll> B;

    int b = 0;
    B[0]++;

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        b += A[i];
        b %= M;
        B[b]++;
    }

    ll count = 0;

    for(auto i = B.begin(); i != B.end(); i++) {
        //cerr << i -> first << " " << i -> second << endl;
        count += i -> second * (i -> second - 1) / 2;
    }

    cout << count << endl;
}