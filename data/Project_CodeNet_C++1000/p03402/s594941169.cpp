#include <iostream>
using namespace std;

int main() {
    int A, B; cin >> A >> B;
    string ans[100];
    cout << "100 100" << '\n';
    for(int i = 0; i < 100; ++i) {
        if(i < 50) ans[i] = string(100, '#');
        else ans[i] = string(100, '.');
    }

    // want to increase . & # independently
    int addA = 1, addB = 1;
    int x = 1, y = 1;
    // white
    while(addA < A) {
        ans[y][x] = '.';
        ++addA;
        x += 2;
        if(x >= 100) {
            x = 1, y += 2;
        }
    }

    // black
    x = 1, y = 99;
    while(addB < B) {
        ans[y][x] = '#';
        ++addB;
        x += 2;
        if(x >= 100) {
            x = 1, y -= 2;
        }
    }

    for(int i=0; i < 100; ++i) cout << ans[i] << '\n';
    return 0;
}