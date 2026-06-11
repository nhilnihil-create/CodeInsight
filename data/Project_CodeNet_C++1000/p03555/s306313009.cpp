#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    vector<char> a(3), b(3);
    rep(i, 0, 3) cin >> a.at(i) >> b.at(i);
    reverse(all(b));
    if (a == b) cout << "YES" << endl;
    else cout << "NO" << endl;
}