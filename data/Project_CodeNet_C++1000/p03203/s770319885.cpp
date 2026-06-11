#include <map>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
 
    map<int, set<int>> b;
    int h, w, n;
    cin >> h >> w >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        b[y].insert(x);
    }

    int ans = h;

    int x = 1, y = 1;

    while (true) {

        auto it = b[y].upper_bound(x);

        int bot = (it == b[y].end()? h + 1: *it);

        ans = min(ans, bot - 1);

        if (x == h || b[y].count(x + 1)) {
            break;
        }
        x++;
        if (!b[y + 1].count(x))
            y++;
    }

    cout << ans << endl;



}
