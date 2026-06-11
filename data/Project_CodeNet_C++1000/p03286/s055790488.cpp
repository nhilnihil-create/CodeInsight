#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define sz(x) (int)(x).size()
#define _USE_MATH_DEFINES
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; 
    cin >> n;
    string s = "";
    while (n != 0) {
        int r = n % 2;
        if (r < 0)
            r += 2;
        n = (n - r) / (-2);
        s += (char)('0' + r); 
    }
    reverse(all(s));
    if (s == "")
        s = "0";
    cout << s << endl;
    return 0;
}