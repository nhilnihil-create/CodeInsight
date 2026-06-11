#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int A, B, cnt = 0; cin >> A >> B;
    for (int i = A; i <= B; ++i) {
        string str = to_string(i);
        int leg = str.length() / 2;
        bool T = true;
        for (int j = 0; j < leg; ++j) {
            if (str[j] != str[(str.length() - 1) - j]) {
                T = false; break;
            }
        }
        if (T) cnt++;
    }
    printf("%d\n", cnt);
}
