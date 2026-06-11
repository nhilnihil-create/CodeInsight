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
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll now = '1';
    ll cnt = 0;
    vl pitsu;
    rep(i,n){
        if(s[i] == now) cnt++;
        else{
            pitsu.push_back(cnt);
            cnt = 1;
            now = s[i];
        }
    }
    pitsu.push_back(cnt);
    if(s[n-1] == '0') pitsu.push_back(0);
    if(k >= (pitsu.size()-1)/2){
        cout<<n<<endl;
        return 0;
    }
    ll score = pitsu[0];
    rep(i,k){
        score += pitsu[2*i+1]+pitsu[2*i+2];
    }
    ll maxi = score;
    rep(i,(pitsu.size()-1)/2-k){
        score -= (pitsu[2*i]+pitsu[2*i+1]);
        score += (pitsu[2*i+2*k+1]+pitsu[2*i+2*k+2]);
        //cout<<score<<endl;
        maxi = max(maxi,score);
    }
    cout<<maxi<<endl;
    return 0;
}
