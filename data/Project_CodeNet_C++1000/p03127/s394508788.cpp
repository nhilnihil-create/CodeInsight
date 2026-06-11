#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

ll gcd (ll a, ll b) {
    if (b > a) {
        ll tmp = b;
        b = a;
        a = tmp;
    }
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    sort(A.begin(), A.end());
    ll a = A.at(0);
    for (int i = 1; i < N; i++) {
        a = gcd(a, A.at(i));
    }

    cout << a << endl;
    return 0;
}