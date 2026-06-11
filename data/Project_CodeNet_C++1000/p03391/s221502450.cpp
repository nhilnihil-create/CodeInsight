#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int N;

int main() {
    cin >> N;
    long long sum = 0;
    int mn = 1e9;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        if (a != b) flag = true;
        if (a > b && mn > b) {
            mn = b;
        }
        sum += b;
    }
    if (flag) {
        sum -= mn;
    } else {
        sum = 0;
    }
    
    cout << sum << endl;
}