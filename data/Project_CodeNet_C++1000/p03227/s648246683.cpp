#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    string s;
    cin >> s;
    if ( s.length() == 2 ) cout << s << endl;
    else {
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}
