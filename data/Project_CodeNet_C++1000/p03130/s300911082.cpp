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
    int bu[5] = {0};
    rep(i, 0, 6){
        int n; cin >> n;
        bu[n]++;
    }
    bool f = true;
    Rep(i, 1, 4){
        if(bu[i] == 0 || bu[i] >= 3) f = false;
    }
    if(f) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
