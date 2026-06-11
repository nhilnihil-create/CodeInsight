#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    vector<int> A(3);
    rep(i, 3) cin >> A[i];
    int K;
    cin >> K;
    
    sort(A.rbegin(), A.rend());
    rep(i, K) A[0] *= 2;
    cout << A[0] + A[1] + A[2] << endl;
    return 0;
}
