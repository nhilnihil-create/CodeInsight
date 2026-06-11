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
    int n; cin >> n;
    int a, b; cin >> a >> b;
    int l = 0, m = 0, h = 0;
    rep(i, 0, n){
        int p; cin >> p;
        if(p <= a) l++;
        if(a < p && p <= b) m++;
        if(p > b) h++;
    }
    cout << min({l, m, h}) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
