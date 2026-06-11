#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        p[i] = make_pair(b, a);  //[a. b)に取り除くべき橋
    }

    sort(p.begin(), p.end());

    int ans = 0;
    for (int i = 0; i < m;) {
        auto now = p[i++];
        while (i < m && p[i].second < now.first) { i++; }
        ans++;
    }
    cout << ans << endl;
}