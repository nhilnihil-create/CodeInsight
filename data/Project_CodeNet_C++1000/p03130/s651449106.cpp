#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector<int> cnt(4, 0);
    for (int i = 0; i < 6; ++i) {
        int a; cin >> a; cnt[a - 1]++;
    }
    if (cnt[0] == 1 && cnt[3] == 1 && cnt[1] == 2 && cnt[2] == 2) printf("%s\n", "YES");
    else printf("%s\n", "NO");
}
