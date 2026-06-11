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
    ll d,g;
    cin>>d>>g;
    vl p(d),c(d);
    ll mondaisu = 0;
    rep(i,d){
        cin>>p[i]>>c[i];
        mondaisu += p[i];
    }
    rep1(i,mondaisu+1){
        rep(j,pow(2,d)){
            ll sum = 0;
            ll maxi = 0;
            ll tensu = 0;
            rep(k,d){
                if(j&(1<<k)){
                    sum += p[k];
                    tensu += 100*(k+1)*p[k]+c[k];
                }
                else maxi = k+1;
            }
            ll nokori = i-sum;
            if(nokori < 0) continue;
            for(ll k = d-1;k>=0 && nokori > 0;k--){
                //cout<<j<<" "<<k<<" "<<(1<<k)<<" "<<(j&(1<<k))<<endl;
                if((j&(1<<k)) == 0){
                    //cout<<k<<endl;
                    if(nokori < p[k]){
                        tensu += 100*(k+1)*nokori;
                        nokori = 0;
                    }
                    else{
                        nokori -= p[k]-1;
                        tensu += (100)*(k+1)*(p[k]-1);
                    }
                }
            }
            if(tensu >= g){
                cout<<i<<endl;
                return 0;
            }
        }
    }
	return 0;
}
