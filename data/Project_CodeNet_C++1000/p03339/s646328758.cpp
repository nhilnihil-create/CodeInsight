#include <iostream>
using namespace std;

int main() {
    int N;
    char S[300100];

    int ans;
    int tmp = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        if (i > 0 && S[i] == 'E') tmp++;
    }

    ans = tmp;

    for (int i = 1; i < N; i++) {
        if (S[i] == 'E') tmp--;
        if (S[i - 1] == 'W') tmp++;
        if (tmp < ans) ans = tmp;
    }

    cout << ans << endl;

    return 0;
}
