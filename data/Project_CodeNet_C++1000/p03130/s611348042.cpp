#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    vector<int> deg(4, 0);
    for (int i = 0; i < 3; ++i) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        deg[x]++;
        deg[y]++;
    }

    int cnt[] = {0, 0};
    for (int i = 0; i < 4; ++i) {
        if (deg[i] == 1) ++cnt[0];
        else if (deg[i] == 2) ++cnt[1];
    }

    if (cnt[0] == 2 && cnt[1] == 2) cout << "YES" << endl;
    else cout << "NO" << endl;

}