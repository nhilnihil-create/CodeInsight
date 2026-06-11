#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int A, B, K; cin >> A >> B >> K;
    vector<int> cnt;
    for (int i = 1; i <= 100; ++i) if (A % i == 0 && B % i == 0) cnt.push_back(i);
    printf("%d\n", cnt[cnt.size() - K]);
}
