#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <numeric>
#include <queue>
#include <cstdio>
#include <cstring>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<n;++i)
#define mrep(i,n) for(ll i=n;i>=0;--i)
#define all(a) (a).begin(),(a).end()
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define pl pair<ll,ll>
#define inf 1001001001001001000
//#define mod 1000000007
#define mod 998244353
#define pi 3.1415926535
using namespace std;
struct __INIT {
	__INIT() {
		cin.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(15);
	}
}__init;



int main(void) {
    ll n;
    cin>>n;
    vl c(n-1),s(n-1),f(n-1);
    rep(i,n-1){
        cin>>c[i]>>s[i]>>f[i];
    }
    rep(i,n-1){
        ll tim = s[i]+c[i];
        for(ll j = i+1;j<n-1;j++){
            if(tim <= s[j]) tim = s[j]+c[j];
            else tim = ceil((double)tim/f[j])*f[j]+c[j];
        }
        cout<<tim<<endl;
    }
    cout<<0<<endl;
    return 0;
}
