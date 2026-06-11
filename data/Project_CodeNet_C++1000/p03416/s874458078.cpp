#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int sum = 0;

    for (int i = A; i <= B; i++) {
        string S = to_string(i);
        string temp = S;

        for (int j = 0; j < S.size() / 2;  j++) {
            swap(S[j], S[S.size() - j - 1]);
        }
        if (S == temp) {
            sum++;
        }

    }
    cout << sum << endl;
    
}
