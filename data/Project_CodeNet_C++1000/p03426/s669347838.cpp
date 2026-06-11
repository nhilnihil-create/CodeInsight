#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int h, w, d;
    cin >> h >> w >> d;
//    vector<vector<int>> a(h, vector<int>(h));
    vector<pair<int, int>> place(h*w+1);
    rep(i, h) rep(j, w) {
        int a;
        cin >> a;
        place[a] = {i+1, j+1};  
    }

//    for ( auto place_num : place ) {
//        cout << place_num.first << ":" << place_num.second << ", ";
//    }
//    cout << endl;

    vector<ll> magic(h*w+1, -1);
    for ( int i = 1; i <= d; ++i ) {
        if ( magic[i] != -1 ) continue;
        magic[i] = 0;
        int idx = i+d;
        while(1) {
            if ( idx >= h*w+1 ) break;
            magic[idx] = magic[idx-d] + ( abs(place[idx].first - place[idx-d].first) + abs(place[idx].second - place[idx-d].second) );
            idx += d;
        }
    }

//    for ( auto magic_num : magic) {
//        cout << magic_num << " ";
//    }

    int q;
    cin >> q;
    vector<ll> ans(q);
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        ans[i] = magic[r] - magic[l];
    }
    for ( auto tmp_ans : ans ) {
        cout << tmp_ans << endl;
    }
    return 0;
}
