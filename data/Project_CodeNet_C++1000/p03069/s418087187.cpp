#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<string>
#include<numeric>
using namespace std;
typedef long long ll;
//ll mod = 1e9+7;
ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> st;
    int ans = 0;
    rep(i, n) {
        if ( st.empty() ) {
            st.push(s[i]);
        }
        else if ( st.top() == '.' ) {
            st.push(s[i]);
        }
        else if ( st.top() == '#' ) {
            if ( s[i] == '.' ) {
                ++ans;
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
