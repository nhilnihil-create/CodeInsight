#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string S; cin >> S;
    int N = 15 - S.length();
    int cnt = 0;
    for (char c : S) if (c == 'o') cnt++;
    if (cnt + N >= 8) printf("%s\n", "YES");
    else printf("%s\n", "NO");
}
