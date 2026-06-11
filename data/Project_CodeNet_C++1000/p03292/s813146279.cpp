#include <iostream>
#include <vector>
using namespace std;

int cal(int a1, int a2, int a3) {
    return abs(a1 - a2) + abs(a2 - a3);
}

int main() {
    vector<int> A(3);
    for (int i = 0; i < 3; i++) cin >> A[i];

    int ans = 1000000000;
    ans = min(ans, cal(A[0], A[1], A[2]));
    ans = min(ans, cal(A[0], A[2], A[1]));
    ans = min(ans, cal(A[1], A[0], A[2]));
    ans = min(ans, cal(A[1], A[2], A[0]));
    ans = min(ans, cal(A[2], A[0], A[1]));
    ans = min(ans, cal(A[2], A[1], A[0]));
    
    cout << ans << endl;
}