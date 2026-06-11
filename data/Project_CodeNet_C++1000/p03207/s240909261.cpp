#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int n;  cin >> n;

    int ans(0),m(0);
    rep(i,n){
        int p;  cin >> p;
        m = max(p,m);
        ans += p;
    }

    ans -= m/2;

    cout << ans << endl;

    return 0;
}