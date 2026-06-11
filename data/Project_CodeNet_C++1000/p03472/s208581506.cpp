
// Problem : D - Katana Thrower
// Contest : AtCoder - AtCoder Beginner Contest 085
// URL : https://atcoder.jp/contests/abc085/tasks/abc085_d
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
 
// krishrawat 
 
 
//----------------------------MACROS-------------------------------------------------
#define pb insert//                                                                 |
#define eb emplace_back//                                                           |
#define ff first//                                                                  |
#define ss second//                                                                 |
typedef long long int ll;//                                                         |
typedef long double ld;//                                                           |
#define all(a) a.begin(), a.end()//                                                 |
#define show(x) cerr << #x << " is " << x << "\n"//                                 |
#define show2(x, y) cerr << #x << " " << #y << " " << x << " " << y << "\n"//       |
typedef vector<ll> vl;//                                                            |
typedef vector<vl> vvl;//                                                           |
typedef pair<ll, ll> pp;//                                                          |
typedef vector<pp> vp;//                                                            |
typedef map<pp, ll> ipi;//                                                          |
typedef map<pp, char> ipc;//                                                        |
typedef map<ll, ll> ii;//                                                           |
typedef set<ll> sl;//                                                               |
typedef multiset<ll> msl;//                                                         |
typedef map<char, ll> ci;//                                                         |
typedef set<pair<ll, ll>> sp;//                                                     |
const ll mod = 1e9 + 7;//                                                           |
const ll N = 1e6 + 1;//                                                             |
//----------------------------------------------------------------------------------
 
 
void solve(){
    ll n,hp;cin>>n>>hp;
    multiset<pp> m;
    for(int i=0;i<n;i++){
    	ll a,b;cin>>a>>b;
    	m.pb({b,a});
    }
    ll slash=0;
    ll ans=0;
    for(auto i:m){
    	slash=max(slash,i.ss);
    }
    while(!m.empty()){
    	auto i=*--m.end();
    	if(hp>0 && i.ff>slash){
    		hp-=i.ff;
    		ans++;
    	}
    	m.erase(--m.end());
    }
    if(hp>0) ans+=ceil(double(hp)/double(slash));
    cout<<ans<<"\n";
}
 
int main()
{	
	/*#ifndef ONLINE_JUDGE 
   		freopen("input.txt", "r", stdin);  
   		freopen("output.txt", "w", stdout); 
   	#endif*/
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
     
 
    ll t;
    t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    
	return 0;
}