#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    // 4/N = 1/h + 1/n + 1/w
    // 4nhw = N * (nw + hw + nh)
    // n = Nhw / (4hw-Nh -Nw)
    ll N;
    cin >> N;
    for(ll h = 1; h <= 3500; h++) {
        for(ll w = 1; w <= 3500; w++) {
            if ((h*w*4-N*(h+w)) <= 0) continue;
            if ((N * h * w) % (h*w*4-N*(h+w)) == 0) {
                ll res = (N * h * w) / (h*w*4-N*(h+w));
                cout << res << " " << h << " " << w << endl;
                return 0;
            }
        }
    }
    return 0;
}


