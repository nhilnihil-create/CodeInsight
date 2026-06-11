#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    set<char> S;
    for (int i = 0; i < N; ++i) {
        char c; cin >> c; S.insert(c);
    }
    if (S.size() == 3) printf("%s\n", "Three");
    else printf("%s\n", "Four");
}
