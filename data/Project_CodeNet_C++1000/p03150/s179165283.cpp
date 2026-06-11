#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<numeric>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main(){
    string s;
    cin >> s;
    rep(i, s.length()) {
        for ( int j = i; j <= s.length(); ++j ) {
            string tmp_s = s.substr(0, i);
            tmp_s += s.substr(j, s.length()-j);
//            cout << tmp_s << endl;
            if ( tmp_s == "keyence" ) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}