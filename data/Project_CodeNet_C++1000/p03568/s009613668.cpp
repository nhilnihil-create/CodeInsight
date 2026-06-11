#include <iostream>
using namespace std;

int main() {
    int n, tmp, ret = 1, even = 1; cin >>n;
    for (int i = 0; i < n; i++) {
        cin >>tmp;
        ret *= 3;
        if (tmp%2==0) even *= 2;
    }
    cout << ret - even << endl;
    return 0;
}