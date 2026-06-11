#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    int ans = 1900*m + 100*(n-m);
    rep(i,m) ans *= 2;
    cout << ans << endl;
}