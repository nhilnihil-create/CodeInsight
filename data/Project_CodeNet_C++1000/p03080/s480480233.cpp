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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int red = 0;
    int blue = 0;
    rep(i, n) {
        if ( s[i] == 'R' ) ++red;
        else               ++blue;
    }
    if ( red > blue ) cout << "Yes" << endl;
    else              cout << "No" << endl;
    return 0;
}
