#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n), h(n);
    rep(i, n)cin >> x[i] >> y[i] >> h[i];
    int idx;
    rep(i, n){
        if(h[i] > 0){
            idx = i;
            break;
        }
    }

    rep(cx, 101)rep(cy, 101){
        int H = h[idx] + abs(cx - x[idx]) + abs(cy - y[idx]);
        bool valid = true;
        rep(i, n){
            if(h[i] != max(0, H - abs(x[i] - cx) - abs(y[i] - cy))){
                valid = false;
                break;
            }
        }
        if(valid){
            cout << cx << ' ' << cy << ' ' << H << endl;
            return 0;
        }
    }
    
}