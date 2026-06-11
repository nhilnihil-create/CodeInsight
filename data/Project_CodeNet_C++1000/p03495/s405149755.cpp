#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    uint N, K;
    cin >> N >> K;

    vector<int> C(N+1, 0);
    for (size_t i=0; i<N; ++i) {
        uint A;
        cin >> A;
        ++C[A];
    }
    sort(C.begin(), C.end(), greater<int>());
    int last = 0;
    for (size_t i=0; i<C.size(); ++i) {
        if (C[i] == 0) break;
        ++last;
    }
    int num = 0;
    for (uint i=K; i<last; ++i) {
        num += C[i];
    }
    cout << num << endl;
}
