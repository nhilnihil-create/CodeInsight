#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int N,M;
    cin >> N >> M;
    vector<int> X(N + 1);
    vector<int> Y(M + 1);
    cin >> X[0] >> Y[0];
    rep(i,N) {
        cin >> X[i + 1];
    }
    rep(j,M) {
        cin >> Y[j + 1];
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    if (X[N] < Y[0]) {
        cout << "No War" << endl;
    }
    else {
        cout << "War" << endl;
    }

}

