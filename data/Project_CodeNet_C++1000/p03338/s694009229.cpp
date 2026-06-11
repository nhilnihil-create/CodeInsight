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
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for ( int i = 1; i < n; ++i ) {
        string x = s.substr(0, i);
        string y = s.substr(i, n-i);
//        cout << i << " " << x << " " << y << endl;
        vector<int> cnt_x(26, 0);
        vector<int> cnt_y(26, 0);
        rep(j, (int)x.size()) ++cnt_x[x[j]-'a'];
        rep(j, (int)y.size()) ++cnt_y[y[j]-'a'];
//        for ( auto p : cnt_x ) cout << p << " ";
//        cout << endl; 
//        for ( auto p : cnt_y ) cout << p << " " ;
//        cout << endl;
        int tmp_ans = 0;
        rep(j, 26) {
            if ( cnt_x[j] > 0 && cnt_y[j] > 0 ) ++tmp_ans;
        }
//        cout << tmp_ans << endl;
        ans = max(tmp_ans, ans);
    }
    cout << ans << endl;
    return 0;
}
