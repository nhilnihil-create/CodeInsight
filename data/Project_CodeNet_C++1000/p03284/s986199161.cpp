#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <stack>
#include <string>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

//--------------------
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

//------------
void func() {
    int N, K;
    cin >> N >> K;
    if (N % K == 0) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
}

int main() {
    func();
    return 0;
}