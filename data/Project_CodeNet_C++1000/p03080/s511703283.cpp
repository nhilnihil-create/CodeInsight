#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    int r = 0, b = 0;
    rep(i, 0, n){
        if(s[i] == 'R') r++;
        else b++;
    }
    if(r > b) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
