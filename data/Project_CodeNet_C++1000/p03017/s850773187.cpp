#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    s = "#" + s + "#";
    auto can_reach = [&](int start, int end) {
        for ( int i = start; i + 1 <= end; ++i ) {
            if ( s[i] == '#' && s[i+1] == '#' ) {
                return false;
            }
        }
        return true;
    };
    if (!can_reach(a, c) || !can_reach(b, d)) {
        cout << "No" << endl;
        return 0;
    }
    if ( c > d ) {
        bool snuke_can_over = false;
        for ( int i = b; i <= d; ++i ) {
            if ( s[i-1] == '.' && s[i] == '.' && s[i+1] == '.' ) {
                snuke_can_over = true;
            }
        }
        if (!snuke_can_over) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
