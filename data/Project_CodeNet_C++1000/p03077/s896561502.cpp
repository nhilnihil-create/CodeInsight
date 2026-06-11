#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N; cin >> N;
    vector<long long> A(5);
    long long mi = 1LL<<60;
    for (int i = 0; i < 5; ++i) cin >> A[i], mi = min(mi, A[i]);
    cout << (N + mi - 1) / mi + 4 << endl;
}