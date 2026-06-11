#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
 
//krishrawat
 
 
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
const ll N = 2e3 + 1;//                                                             |
//----------------------------------------------------------------------------------


//solution
void solve()
{   
    
    ll a,b;cin>>a>>b;
    msl m;
    for(int i=0;i<a;i++){
        ll k;cin>>k;m.pb(k);
    }
    vp v(b);
    for(int i=0;i<b;i++){
        cin>>v[i].ss>>v[i].ff;
    }
    sort(all(v));
    reverse(all(v));
    
    
    ll ans=0;
    for(auto &i:v){
        ll w=i.ss;
        while(w){
            if(!m.empty()){
                if(*m.begin()>=i.ff){
                    ans+=*m.begin();
                }
                else{
                    ans+=i.ff;
                    w--;
                }
                m.erase(m.begin());
            }
            else break;
        }
    }
    while(!m.empty()){
        ans+=*m.begin();
        m.erase(m.begin());
    }
    cout<<ans<<"\n";
    
}
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    ll t; t=1;
    //cin>>t;
    while(t--) solve(); return 0;
}