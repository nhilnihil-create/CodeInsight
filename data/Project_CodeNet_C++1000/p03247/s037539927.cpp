#include <iostream>
#include <vector>
using namespace std;

using pll = pair<long long, long long>;

int main() {
    int N; cin >> N;
    vector<pll> pos(N);
    for (int i = 0; i < N; ++i) cin >> pos[i].first >> pos[i].second;
    
    int par = (abs(pos[0].first) + abs(pos[0].second)) % 2;
    for (int i = 0; i < N; ++i) {
        int par2 = (abs(pos[i].first) + abs(pos[i].second)) % 2;
        if (par2 != par) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    vector<long long> d;
    for (int i = 30; i >= 0; --i) d.push_back(1LL<<i);
    if (par % 2 == 0) d.push_back(1);
    cout << d.size() << endl;
    for (int j = 0; j < d.size(); ++j) cout << d[j] << " ";
    cout << endl;
        
    for (int i = 0; i < N; ++i) {
        long long xt = pos[i].first, yt = pos[i].second;
        long long x = 0, y = 0;
        for (int j = 0; j < (int)d.size(); ++j) {
            if (abs(x - xt) >= abs(y - yt)) {
                if (x >= xt) x -= d[j], cout << "L";
                else x += d[j], cout << "R";
            }
            else {
                if (y >= yt) y -= d[j], cout << "D";
                else y += d[j], cout << "U";
            }
        }
        cout << endl;
    }
}