#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int N;
    cin >> N;
    long long int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    long long int min_val = min(A, min(B, min(C, min(D, E))));
    long long int res = ceil(N*1.0 / min_val) + 4;
    cout << res << endl;
    return 0;
}