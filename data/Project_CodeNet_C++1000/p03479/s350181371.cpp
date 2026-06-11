#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;
    long long num = x;
    long long count = 1;
    while (true) {
        if (num * 2 <= y) {
            num *= 2;
            count++;
        }
        else goto next;
    }
    next:
    cout << count << endl;
}