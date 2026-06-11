#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, A, B; cin >> N >> A >> B;
    vector<int> a(3, 0);
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        if (x <= A) a[0]++;
        else if (A + 1 <= x && x <= B) a[1]++;
        else if (x >= B + 1) a[2]++;
    }
    sort(a.begin(), a.end());
    printf("%d\n", a[0]);
}
