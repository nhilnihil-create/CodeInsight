#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    ll n,a,b,c,d,e;
    cin >> n >> a >> b >> c >> d >> e;
    ll neck = min(min(min(min(a,b),c),d),e);
    ll res = (n-1)/neck + 5;
    cout << res << endl;
    return 0;
}