#include <bits/stdc++.h>
 
 
#define se second
#define sz(x) (int)(x.size())
#define ll long long
#define rep(i,x,y) for(int i = x; i <= y; ++i)
#define repr(i,x,y) for(int i = x; i >= y; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define ull unsigned ll
 
#define pi 3.14159265358979
 
 
using namespace std;
 
const int N = (int)(1e6) + 322;
const ll INF = 2e18 + 17;
const int inf = 2e9;
const int mod = 1000000007;
const double eps = 1e-9;
 
int gcd(int a, int b) { return b ? gcd (b, a % b) : a; }
 
int nbr_bits(int a){
    return log2(a)+1;
}
 
 
ll fastpow(int a, int n, int mod) {
    if(n==0)
        return 1;
    if(n%2==0){
        ll res = fastpow(a,n/2,mod);
        res*=res;
        res%=mod;
        return res;
    }
    ll res = (fastpow(a,n-1,mod)*a)%mod;
    return res;
    
}
 
// ----------------------------------------------------

map<int,pair<string,int> > occ;
int n;

bool comp(int a, int b){
    if(occ[a].first==occ[b].first) return occ[a].second > occ[b].second ;
    return occ[a].first < occ[b].first;
}
 
 
int main()
{
        ios_base::sync_with_stdio(false);
//      cin >> t ;
//      while(t--){
//      
        cin >> n ;
        int tab[n+1];
        occ.clear();
        rep(i,1,n){
            
            tab[i] = i;
            int a; string s;
            cin >> s >> a;
            occ[i].first = s; 
            occ[i].second = a;  
            
        }
        
        sort(tab+1,tab+n+1,comp);
        rep(i,1,n){
              cout << tab[i] << " " ;
//           if(tab[n]!= tab[n-1] && i==n-1) cout << tab[n] << " " ;
        }
        cout << endl;
//  }
    
    return 0;
}