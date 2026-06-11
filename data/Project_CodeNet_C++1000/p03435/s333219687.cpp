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
    vvl pitsu(3,vl(3,0));
    rep(i,3) rep(j,3) cin>>pitsu[i][j];
    bool a1 = pitsu[1][0]-pitsu[0][0] == pitsu[1][1]-pitsu[0][1];
    a1 &= pitsu[1][1]-pitsu[0][1] == pitsu[1][2]-pitsu[0][2];
    bool a2 = pitsu[2][0]-pitsu[1][0] == pitsu[2][1]-pitsu[1][1];
    a2 &= pitsu[2][1]-pitsu[1][1] == pitsu[2][2]-pitsu[1][2];
    bool b1 = pitsu[0][1]-pitsu[0][0] == pitsu[1][1]-pitsu[1][0];
    b1 &= pitsu[1][1]-pitsu[1][0] == pitsu[2][1]-pitsu[2][0];
    bool b2 = pitsu[0][2]-pitsu[0][1] == pitsu[1][2]-pitsu[1][1];
    b2 &= pitsu[1][2]-pitsu[1][1] == pitsu[2][2]-pitsu[2][1];
    if(a1 && a2 && b1 && b2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
	return 0;
}
