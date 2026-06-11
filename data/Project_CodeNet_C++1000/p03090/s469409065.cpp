
#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);
// like n-partite graph, no-intra-connection
// even f(6): (1, 6) (2, 5) (3, 4)
// odd: f(7): (1, 6) (2, 5), (3, 4), (7)
int main() {
    int n;
    cin >> n;
    set<pair<int, int>> cand;
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++)
            cand.insert({i, j});
    }
    // disconnect intra-link
    int upper = (n%2 == 0) ? n : n-1;
    int lower = 1;
    while (lower < upper) {
        cand.erase({lower++, upper--});
    }
    cout << cand.size() << endl;
    for(auto p: cand)
        cout << p.first << " " << p.second << endl;
    return 0;
}


