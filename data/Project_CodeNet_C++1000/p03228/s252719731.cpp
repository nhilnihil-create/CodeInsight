#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {   
    int a, b, k;
    cin >> a >> b >> k;
    int flag = 1;
    for (int i = 0; i < k; i++) {
        if (flag == 1) {
        if (a % 2 == 1) {
            a--;
        }
        b += a / 2;
        a /= 2;
            flag = -1;
        } else {
            if (b % 2 == 1) {
                b--;
            }
            a += b / 2;
            b /= 2;
            flag = 1;
        }

    }
    cout << a << " " << b << endl;
}


