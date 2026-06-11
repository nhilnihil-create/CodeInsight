#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

uint32_t ceil2(uint32_t a)
{
    uint32_t b = 1;
    while (a >= b) {
        b <<= 1;
    }
    return b;
}

int main()
{
    int N;
    cin >> N;

    unordered_multiset<int> S;
    vector<int> A(N);
    for (auto &&a : A) {
        cin >> a;
        S.insert(a);
    }
    sort(begin(A), end(A), greater<>());

    int ans = 0;
    for (auto a : A) {
        auto pa = S.find(a);
        if (pa == S.end()) {
            continue;
        }
        S.erase(pa);

        int b = ceil2(a) - a;

        auto pb = S.find(b);
        if (pb != S.end()) {
            S.erase(pb);
            ans += 1;
        }
    }

    cout << ans << '\n';
}
