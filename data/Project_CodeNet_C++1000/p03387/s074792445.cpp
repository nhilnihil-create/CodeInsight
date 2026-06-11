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
    ll a,b,c;
    cin>>a>>b>>c;
    vl ngo = {a,b,c};
    sort(all(ngo));
    if(ngo[2]%2 == 0 && ngo[1]%2 == 0 && ngo[0]%2 == 0){
        cout<<((ngo[2]-ngo[0])/2+(ngo[2]-ngo[1])/2)<<endl;
    }
    else if(ngo[2]%2 == 1 && ngo[1]%2 == 0 && ngo[0]%2 == 0){
        cout<<((ngo[1]-ngo[0])/2+ngo[2]-ngo[1])<<endl;
    }
    else if(ngo[2]%2 == 0 && ngo[1]%2 == 1 && ngo[0]%2 == 0){
        cout<<(1+(ngo[2]+1-ngo[1])/2+(ngo[2]+1-ngo[0])/2)<<endl;
    }
    else if(ngo[2]%2 == 0 && ngo[1]%2 == 0 && ngo[0]%2 == 1){
        cout<<(1+(ngo[2]+1-ngo[1])/2+(ngo[2]+1-ngo[0])/2)<<endl;
    }
    else if(ngo[2]%2 == 1 && ngo[1]%2 == 1 && ngo[0]%2 == 0){
        cout<<(1+(ngo[2]+1-ngo[1])/2+(ngo[2]+1-ngo[0])/2)<<endl;
    }
    else if(ngo[2]%2 == 1 && ngo[1]%2 == 0 && ngo[0]%2 == 1){
        cout<<(1+(ngo[2]+1-ngo[1])/2+(ngo[2]+1-ngo[0])/2)<<endl;
    }
    else if(ngo[2]%2 == 0 && ngo[1]%2 == 1 && ngo[0]%2 == 1){
        cout<<((ngo[1]-ngo[0])/2+ngo[2]-ngo[1])<<endl;
    }
    else if(ngo[2]%2 == 1 && ngo[1]%2 == 1 && ngo[0]%2 == 1){
        cout<<((ngo[2]-ngo[1])/2+(ngo[2]-ngo[0])/2)<<endl;
    }
	return 0;
}
