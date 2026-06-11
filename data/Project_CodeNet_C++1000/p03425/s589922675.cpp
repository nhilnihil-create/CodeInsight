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
    map<char,ll> pitsu;
    pitsu['M'] = 0;
    pitsu['A'] = 0;
    pitsu['R'] = 0;
    pitsu['C'] = 0;
    pitsu['H'] = 0;
    ll n;
    cin>>n;
    rep(i,n){
        string s;
        cin>>s;
        if(s[0] == 'M' || s[0] == 'R' || s[0] == 'C' || s[0] == 'H'||s[0] == 'A'){
            pitsu[s[0]]++;
        }
    }
    string march = "MARCH";
    ll ans = 0;
    rep(i,5){
        for(ll j = i+1;j<5;j++){
            for(ll k = j+1;k<5;k++){
                ans += pitsu[march[i]]*pitsu[march[j]]*pitsu[march[k]];
            }
        }
    }
    cout<<ans<<endl;
	return 0;
}
