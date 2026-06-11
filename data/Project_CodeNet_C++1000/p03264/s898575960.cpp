#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <map>
using namespace std;

int main() {
    int k;
    cin >> k;
    if (k % 2 == 1) {
        int ans;
        ans = (k / 2) * (k + 1) / 2;
        cout << ans << endl;
    }
    else cout << (k / 2) * (k / 2) << endl;
}
