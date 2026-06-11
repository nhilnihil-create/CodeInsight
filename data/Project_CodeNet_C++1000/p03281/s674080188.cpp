#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <regex>
using namespace std;

vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            res.push_back(i);
            if (N / i != i) res.push_back(N / i);
        }
    }
    sort(res.begin(), res.end());

    return res;
}

int main() {
    int N;
    cin >> N;

    int ans = 0;
    for (int i=1; i<=N; i++) {
        if (i % 2 == 0) continue;

        if (enum_divisors(i).size() == 8) ans++;
    }

    cout << ans << endl;
    
    return 0;
}