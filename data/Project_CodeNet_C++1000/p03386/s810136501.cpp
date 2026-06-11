#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int A, B, K; cin >> A >> B >> K;
    vector<int> ans;
    for (int i = A; i <= B; ++i) {
        if (A + (K - 1) >= i || B - (K - 1) <= i) ans.push_back(i);
    }
    for (int i = 0; i < ans.size(); ++i) printf("%d\n", ans[i]);
}
