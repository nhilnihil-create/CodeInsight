#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int N;
    int ans;
    string A, B, C;

    cin >> N;
    cin >> A;
    cin >> B;
    cin >> C;

    for (int i = 0; i < N; i++) {
        set<char> s;
        s.insert(A[i]);
        s.insert(B[i]);
        s.insert(C[i]);
        ans += (s.size()-1);
    }
    cout << ans << endl;
}
