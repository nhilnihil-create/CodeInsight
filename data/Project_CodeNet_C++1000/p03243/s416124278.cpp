#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 9; i++) {
        if ((i - 1) * 111 < n && n <= i * 111) {
            cout << i * 111 << endl;
            return 0;
        }
    }
}