#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int main() {
    vector<int> M;
    int sum = 0, diff = 10e7, tmp = 0, x = 1;
    for (int i = 0; i < 5; ++i) {
        int a; cin >> a; M.push_back(a);
        if (diff >= a % 10 && a % 10 != 0) {
            diff = a % 10, tmp = a;
        }
    }
    for (int i = 0; i < 5; ++i) {
        if (M[i] == tmp && x == 1) {
            x--; continue;
        }
        if (M[i] % 10 == 0) sum += M[i];
        else sum += M[i] + (10 - (M[i] % 10));
    }
    printf("%d\n", sum + tmp);
}