#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0 ; i < (int)(n) ; i++)
typedef long long ll;
////////////////////////////////////////////////
int main() {
    int n;
    string c;
    cin >> n >> c;
    int ans = n;
    vector<int> w(n, 0), e(n, 0);
    rep(i,n-1){
        w[i+1]=w[i]+(c[i]=='W');
        e[n-i-2]=e[n-i-1]+(c[n-i-1]=='E');
    }
    rep(i,n){
        ans=min(ans, w[i]+e[i]);
    }
    cout << ans << endl;
}