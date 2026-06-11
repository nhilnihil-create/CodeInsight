#include <iostream>
using namespace std;
int main() {
    string S; cin >> S;
    int ans = 700;
    for (char c : S) if (c == 'o') ans += 100;
    printf("%d\n", ans);
}