#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

//            0  0  0
// e.g 14 = > 1, 2, 4, 7 => 7-14
//           \ \   \3 -- => 3-6
//            \ \1 ----- => 1-2
//            0 -------- => 0
// 10 edges, n <= 2^4
int main() {
    int L, nbits = 0;
    cin >> L;
    if (L < 50) {
        cout << 2 << " " << L << endl;
        for(int i = 0; i < L; i++)
            cout << "1 2 " << i << endl;
        return 0;
    }
    vector<vector<int>> ans;
    while ((1<<nbits) < L) {
        nbits += 1;
    }
    // cout << nbits << endl;
    int last = nbits-1;
    for(int i = 0; i < nbits-2; i++) {
        ans.push_back({i, i+1, 0});
        ans.push_back({i, i+1, (1<<i)});
    }
    for(int bit = nbits-2; bit >= 0; bit--) {
        while (L-(1<<bit) >= 0) {
            ans.push_back({bit, last, L-(1<<bit)});
            L -= (1<<bit);
        }
    }
    cout << nbits << " " << ans.size() << endl;
    for(auto vec: ans) {
        cout << vec[0]+1 << " " << vec[1]+1 << " " << vec[2] << endl;
    }
    return 0;
}

