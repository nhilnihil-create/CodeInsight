#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    cin >> num;

    for (int i = 0; i < 1000; i++) {
        if ((num + i) % 111 == 0) {
            cout << num+i;
            break;
        }
    }
    //
}
