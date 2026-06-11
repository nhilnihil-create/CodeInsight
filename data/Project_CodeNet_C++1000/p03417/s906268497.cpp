#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    ll n,m; cin >> n >> m;
    ll change = 1;
    if(n==1) change*=(-1);
    if(m==1) change*=(-1);
    cout << (n-2)*(m-2)*change << endl;
}