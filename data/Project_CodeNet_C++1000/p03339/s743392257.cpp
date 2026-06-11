#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int w = 0, e = 0;
    vector<int> W(n+1, 0);
    vector<int> E(n+1, 0);
    rep(i,n) {
        if(s[i]=='W'){
            w++;
            W[i+1]=w;
        }else {
            W[i+1] = w;
        }
    }

    for(int i = n-1; i >= 1; --i) {
        if(s[i]=='E') {
            e++;
            E[i-1]=e;
        } else {
            E[i-1] = e;
        }
    }
    int ans = 999999999;
    rep(i,n) {
        int cnt = E[i] + W[i];
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}