#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
using ll = long long int;

int main() {
    int h, w, n; cin >> h >> w >> n;
    int ans = h;
    unordered_map<ll, int> field;
    vector<vector<int>> block(h);
    for(int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        x--; y--;
        field[1LL * x * 1e6 + y] = 1;
        if(x > y){
            block[x].push_back(x - y);
        }
    }
    int rank = 1;
    for(int i=0; i<h; i++){
        for(auto& v:block[i]){
            if(v >= rank){
                cout << i << endl;
                return 0;
            }
        }
        if(field[1LL * i * 1e6 + (i - rank + 1)] == 1){rank++;}
    }
    cout << ans << endl;
    return 0;
}