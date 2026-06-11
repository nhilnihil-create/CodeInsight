#include <bits/stdc++.h>
using namespace std;

bool rev(int n) {
    string S = to_string(n);
    string RS;
    for (int i = S.length() - 1; i >= 0; i--) {
        RS += S[i];
    }
    return S == RS;
 }

int main() {
    int A, B;
    cin >> A >>B;

    int cnt = 0; 
    for (int i = A; i <= B; i++) {
        if (rev(i))
            cnt++;
    }
    cout << cnt << endl;
}