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
    Vl v(n);
    int a; cin >> a;
    int ans = 0;
    rep(i, 1, n){
        int b; cin >> b;
        if(b == a){
            ans++;
            a = 0;
        }else{
            a = b;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
