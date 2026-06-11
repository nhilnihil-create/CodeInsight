// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define add(x) accumulate(x)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end() 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
const ll mod = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
//
//
int main(){ 

        ll t=1;
        // cin>>t;
        while(t--){
                ll n;
                cin>>n;
                int arr[n];
                vll vec(21,0);
                rep(i,0,n)
                        cin>>arr[i];
                ll ans=0,l=0;
                rep(i,0,n){
                        ll k=arr[i],p=0;
                        while(k){
                                if(k&1)
                                        vec[p]++;
                                ++p;
                                k>>=1;
                        }
                        rep(j,0,20){
                                if(vec[j]>1){
                                        rep(r,l,i){
                                                k=arr[r],p=0;
                                                while(k){
                                                        if(k&1)
                                                                vec[p]--;
                                                        ++p;
                                                        k>>=1;
                                                }
                                                ++l;
                                                if(vec[j]==1)
                                                        break;
                                        }
                                }
                        }
                        ans+=(i-l+1);
                }
                cout<<ans<<'\n';
        }
}
