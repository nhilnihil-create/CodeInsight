#include <iostream>
using namespace std;

char S[50];
int N;
int K;

int main() {
    cin >> N >> K;
    cin >> S;
    for (int i = 0; i < N; i++) {
        if (S[i] != 'A' && S[i] != 'B' && S[i] != 'C') {
            return 0;
        }
    }
    for (int i = 0; i < N; i++) {
        if (i == (K - 1)) {
            putchar(tolower(S[i]));
        }
        else {
            cout << S[i];
        }
    }
}
