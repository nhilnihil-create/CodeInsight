#include <bits/stdc++.h>
using namespace std;
int main () {
    int N;
    string A, B, C;
    cin >> N >> A >> B >> C;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        set<char> s;
        s.insert(A[i]);
        s.insert(B[i]);
        s.insert(C[i]);
        switch (s.size()) {
            case 3:
                ans += 2;
                break;
            case 2:
                ans += 1;
                break;
            case 1:
                ans += 0;
                break;
        }
    }
    cout << ans << endl;
}