#include <iostream>
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
    int n;
    cin >> n;
    int sum = ( n&1 ) ? n : n + 1;
    vector<pair<int, int>> ans;
    for ( int i = 1; i <= n; ++i ) {
        for ( int j = i + 1; j <= n; ++j ) {
            if ( i + j == sum ) continue;
                ans.emplace_back(i, j);
        }
    }
    cout << ans.size() << endl;
    for ( auto tmp_ans : ans ) {
        cout << tmp_ans.first << " " << tmp_ans.second << endl;
    }
    return 0;
}
