#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string S, T; cin >> S >> T;
    reverse(T.begin(), T.end());
    if (S == T) printf("%s\n", "YES");
    else printf("%s\n", "NO");
}