#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, result = 0, prev, count = 1;
    cin >> n >> prev;
    for (int a; cin >> a; ) {
        if (a == prev) {
            count++;
        } else {
            result += count / 2;
            count = 1;
        }
        prev = a;
    }
    result += count / 2;
    cout << result;
    return 0;
}