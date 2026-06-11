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
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    string s;
    cin >> s;
    stack<char> st;
    int ans = 0;
    rep(i, (int)s.size()) {
        if (st.empty()) {
            st.push(s[i]);
        }
        else if ( st.top() == '0' && s[i] == '1') {
            st.pop();
            ++ans;
        }
        else if ( st.top() == '1' && s[i] == '0' ) {
            st.pop();
            ++ans;
        }
        else {
            st.push(s[i]);
        }
        //cout << i << " " << st.size() << " " << ans << endl;
    }
    cout << ans * 2 << endl;
}
