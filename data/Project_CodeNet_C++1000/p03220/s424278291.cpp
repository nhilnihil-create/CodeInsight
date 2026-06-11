#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, t, a, ret, tmp, min_diff = 100000000;
    cin >>n >>t >>a;
    t *= 1000;
    a *= 1000;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        tmp = abs(a-(t-tmp*6));
        if (tmp < min_diff) {
            ret = i;
            min_diff = tmp;
        }
    }
    cout << ret<< endl;
    return 0;
}