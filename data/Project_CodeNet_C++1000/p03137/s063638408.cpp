#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;


int main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(M), D(M-1);
    for(int i=0; i<M; i++) cin >> X[i];

    //コマが座標より大きい
    if(N >= M) {
        cout << 0 << endl;
        return 0;
    }

    sort(X.begin(), X.end());
    for(int i=0; i<M-1; i++) {
        D[i] = abs(X[i]-X[i+1]);
    }

    sort(D.begin(), D.end());
    int count = 0;
    for(int i=0; i<M-N; i++) {
        count += D[i];
    }
    cout << count << endl;
}