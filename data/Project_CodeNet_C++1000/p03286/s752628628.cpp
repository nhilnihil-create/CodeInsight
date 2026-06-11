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

string tobin(ll a){
    string ret = "";
    while(a>0){
        if(a%2 == 0) ret += "0";
        else ret += "1";
        a /= 2;
    }
    reverse(all(ret));
    return ret;
}

ll add(ll n,ll a){
    //cout<<"in :"<<tobin(n)<<" "<<tobin(a)<<endl;
    ll i = 1;
    while(i<=a){
        if(a&i){
            if(!(n&i)){
                n += i;
            }
            else{
                if(n&(i<<1)){
                    n -= i;
                    n -= (i<<1);
                }
                else{
                    n -= i;
                    n = add(n,i<<1);
                    n = add(n,i<<2);
                }
            }
        }
        i <<= 1;
    }
    //cout<<"out :"<<n<<endl;
    return n;
}

int main(void) {
    ll n;
    cin>>n;
    string s = tobin(abs(n));
    reverse(all(s));
    if(n == 0){
        cout<<0<<endl;
    }
    else if(n < 0){
        n = abs(n);
        ll ans = 0;
        rep(i,s.size()){
            if(s[i] == '1'){
                if(i%2 == 0){
                    ans = add(ans,pow(2,i+1));
                }
                ans = add(ans,pow(2,i));
            }
        }
        cout<<tobin(ans)<<endl;
    }
    else{
        ll ans = 0;
        //cout<<tobin(ans)<<endl;
        rep(i,s.size()){
            if(s[i] == '1'){
                if(i%2 == 1){
                    //cout<<"i"<<i<<endl;
                    ans = add(ans,pow(2,i+1));
                }
                ans = add(ans,pow(2,i));
            }
            //cout<<tobin(ans)<<endl;
        }
        cout<<tobin(ans)<<endl;
    }
	return 0;
}
