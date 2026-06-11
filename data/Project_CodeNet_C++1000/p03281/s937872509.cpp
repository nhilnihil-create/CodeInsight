#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int counter(int x) {
    set<int> s;
    for (int i = 1; i * i <= x; ++i) if (x % i == 0) s.insert(i), s.insert(x / i);
    return s.size();
}
int main() {
    int N, cnt = 0; cin >> N;
    for (int i = 9; i <= N; i += 2) {
        if (counter(i) == 8) cnt++;
    }
    printf("%d\n", cnt);
}
