#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    double i_place, N, K;
    cin >> N >> K;
    vector<double> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
        if(A[i] == 1) i_place = i;
    }

    double before_count = i_place;
    double after_count = N - 1 - i_place;
    int X, Y;
    cout << 1 + ceil((N-K)/(K-1)) << endl;
}