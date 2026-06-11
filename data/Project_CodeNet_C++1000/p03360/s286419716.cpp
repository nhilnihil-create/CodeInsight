#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    ll a[3];rep(i,3)cin>>a[i];
    sort(a,a+3);
    int k;cin>>k;
    rep(i,k)a[2]*=2;
    cout<<a[0]+a[1]+a[2]<<endl;
	return 0;
}