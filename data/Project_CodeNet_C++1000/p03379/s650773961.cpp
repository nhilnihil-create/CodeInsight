#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for(int i=0; i<N; i++) cin >> X[i];
    Y = X;
    sort(Y.begin(), Y.end());

    //中央値Bi
    for(int i=0; i<N; i++) {
        if(X[i] < Y[N/2]) {
            cout << Y[N/2] << endl;
        }
        else {
            cout << Y[N/2-1] << endl;
        }
    }
}