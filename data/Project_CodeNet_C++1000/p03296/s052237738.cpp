#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> a(N, 0);
    for (int i = 0; i < N; ++i) cin >> a[i];
    int cnt = 0, tmp = 10e7;
    for (int i = 1; i < N; ++i) {
        if (a[i] == a[i - 1]) {
            cnt++; a[i] = tmp; tmp--;
        }
    }
    printf("%d\n", cnt);
}
