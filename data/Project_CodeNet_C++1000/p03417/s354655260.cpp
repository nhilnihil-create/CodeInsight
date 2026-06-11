#include <iostream>
typedef long long ll;
using namespace std;

int main(void) {
    ll N,M;cin>>N>>M;
    if (N > 2 && M > 2) cout << (N - 2) * (M - 2) << endl;
    else if (M == 2 || N == 2) cout << 0 << endl;
    else if (M == 1 && N > 2) cout << N - 2 << endl;
    else if (M > 2 && N == 1) cout << M - 2 << endl;
    else if (M == 1 && N == 1) cout << 1 << endl;
    return 0;
}