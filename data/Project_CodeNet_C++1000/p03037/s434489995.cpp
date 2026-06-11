#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main() {
    int n,m;
    cin >> n >> m;
    int l = 0, r = n+1;;
    rep(i,m){
        int tl, tr;
        cin >> tl >> tr;
        l = max(l,tl);
        r = min(r,tr);
    }
    if(l>r) cout << 0 << endl;
    else cout << r-l+1 << endl;
}