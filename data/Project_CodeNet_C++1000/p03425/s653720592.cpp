#include<iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    string s;
    long long count[5]{};
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s[0] == 'M') count[0]++;
        else if (s[0] == 'A') count[1]++;
        else if (s[0] == 'R') count[2]++;
        else if (s[0] == 'C') count[3]++;
        else if (s[0] == 'H') count[4]++;
    }

    long long ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            for (int k = j + 1; k < 5; k++) {
                ans += count[i] * count [j] * count[k];
            }
        }
    }

    cout << ans << endl;
}