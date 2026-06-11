#include <iostream>
using namespace std;

int main() {
    int D, N, ans;
    cin >> D >> N;
    switch(D) {
    case 0:
        ans = 1;
        break;
    case 1:
        ans = 100;
        break;
    case 2:
        ans = 10000;
        break;
    }
    if(N == 100) {
        cout << ans * N + ans << endl;
    } else {
        cout << ans * N << endl;
    }
}