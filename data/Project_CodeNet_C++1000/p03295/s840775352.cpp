#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > vec;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        vec.push_back(make_pair(b, a));
    }
    sort(vec.begin(), vec.end());
    int recent_broken_bridge = 0; //橋の左の頂点を持つ
    int ret = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].second <= recent_broken_bridge) {
            ;
        }
        else {
            ret++;
            recent_broken_bridge = vec[i].first - 1;
        }
    }
    cout << ret << endl;
    return 0;
}