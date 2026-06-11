#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i,n) cin >> d.at(i);
    vector<int> num(101);
    int ans = 0;
    rep(i,n) num.at(d.at(i))++;
    rep(i,101){
        if(num.at(i) > 0 ) ans++;
    }
    cout << ans << endl;
}