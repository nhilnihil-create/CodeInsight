#include <iostream>
using namespace std;
int main() {
    string S; cin >> S; int ans = 0;
    for (int i = 0; i < 4; i++) if (S[i] == '2') ans++;
    printf("%d\n", ans);
}