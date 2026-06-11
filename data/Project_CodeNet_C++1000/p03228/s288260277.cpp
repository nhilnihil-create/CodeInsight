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
    ll a, b, k; cin >> a >> b >> k;
    int f = 1;
    while(k){
        if(f == 1){
            k--;
            b += a/2;
            a /= 2;
            f = 0;
        }else if(f == 0){
            k--;
            a += b/2;
            b /= 2;
            f = 1;
        }
    }
    cout << a << " " << b << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
