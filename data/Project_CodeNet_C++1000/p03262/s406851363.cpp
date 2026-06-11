#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

ll gcd(ll a, ll b) {
    if(a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int N, X, a;
    cin >> N >> X;
    vector<int> V(N+1);
    V[0] = X;
    vector<int> D;
    for(int i=1; i<N+1; i++) cin >> V[i];

    for(int i=0; i<N; i++) {
        a = abs(V[i]-V[i+1]);
        D.push_back(a);
    }
    if(D.size() == 1) {
        cout << D[0] << endl;
        return 0;
    }

    int Z = gcd(D[0], D[1]);

    for(int i=2; i<D.size(); i++) {
        Z = gcd(Z, D[i]);
    }
    cout << Z << endl;
}