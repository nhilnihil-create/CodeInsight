#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for(int i=0; i<N; i++) cin >> X[i];

    Y = X;
    sort(Y.begin(), Y.end());
    ll mid_l = Y[N/2 - 1], mid_r = Y[N/2];

    for(int i=0; i<N; i++) {
        if(X[i] <= mid_l) {
            cout << mid_r << endl;
        }
        else if(X[i] >= mid_r) {
            cout << mid_l << endl;
        }
    }
}