#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int K;
    cin >> K;
    cout << ((K - 1) / 2 + 1) * (K / 2) << endl;
    return 0;
}
