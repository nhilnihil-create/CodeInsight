#include <iostream>
using namespace std;
int main() {
    string S; cin >> S;
    int a_cnt = 0, b_cnt = 0, c_cnt = 0;
    for (char c : S) {
        if (c == 'a') a_cnt++;
        else if (c == 'b') b_cnt++;
        else c_cnt++;
    }
    if (a_cnt == 1 && b_cnt == 1 && c_cnt == 1) printf("%s\n", "Yes");
    else printf("%s\n", "No");
}