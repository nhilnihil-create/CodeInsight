#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int N , M , count = 0;
    cin >> N >> M;
    vector<int> X(M) , Y(M - 1);
    for(int i = 0; i < M; i++) {
        cin >> X[i];
    }
    sort(X.begin() , X.end());
    for(int i = 0; i < M - 1; i++) {
        Y[i] = X[i + 1] - X[i];
    }
    sort(Y.begin(), Y.end());
    for(int i = 0; i < max(0 , M - N); i++) {
        count += Y[i];
    }
    cout << count << endl;
}