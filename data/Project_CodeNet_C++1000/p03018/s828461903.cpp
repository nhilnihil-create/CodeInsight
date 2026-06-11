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
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    string s;
    cin >> s;
    ll ret = 0;
    int cnt = 0;
    int n = s.length();
    rep(i, n) {
        if ( s[i] == 'A' ) ++cnt;
        else if ( s[i] == 'B' ) {
            if ( i + 1 < n && s[i+1] == 'C' ) {
                ret += cnt;
                ++i;
            }
            else cnt = 0;
        }
        else cnt = 0;

    }
    cout << ret << endl;
    return 0;
}
