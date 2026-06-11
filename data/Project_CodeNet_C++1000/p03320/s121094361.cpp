#include <algorithm>
#include <vector>
#include <iostream>
#define MAX 1000000000000000LL

using namespace std;
int main() {
    vector<long long> S({1, 2, 3, 4, 5, 6, 7, 8});
    for (int a = 0; a < 200; a++) {
        if (a % 10 == 9) continue;
        int sum = 0, temp = a;
        while (temp > 0) { sum += temp % 10; temp /= 10; }
        int k = (a + 1 - sum + 8) / 9;
        if (k >= 15) continue;
        long long n = a + 1;
        while (k--) { n *= 10; }
        while (n <= MAX) { S.push_back(n - 1); n *= 10; }
    }
    sort(S.begin(), S.end());
    int k; cin >> k;
    for (int i = 0; i < k; i++) cout << S[i] << endl;
}
