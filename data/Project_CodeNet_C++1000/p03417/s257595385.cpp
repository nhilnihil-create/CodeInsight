#include <iostream>
using namespace std;

int main(){
    long long N,M;
    cin >> N >> M;
    if(N == 1 && M == 1) cout << 1 << '\n';
    else if (N == 1 || M == 1) cout << max(M, N) - 2 << '\n';
    else cout << N*M - 2*N - 2*M + 4 << '\n';
    return 0;
}