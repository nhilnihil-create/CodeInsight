#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define LB(a,x) lb(all(a),x)-a.begin()
#define UB(a,x) ub(all(a),x)-a.begin()
#define mod 1000000007
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n,Q;
    string s;
    cin>>n>>s>>Q;
    while(Q--){
        ll k;
        cin>>k;
        ll ans=0;
        ll cd=0,cm=0,cdm=0;
        rep(i,n){
            if(s[i]=='D') cd++;
            else if(s[i]=='M'){
                cm++;
                cdm+=cd;
            }
            else if(s[i]=='C'){
                ans+=cdm;
            }
            if(i-k+1>=0){
                if(s[i-k+1]=='D'){
                    cd--;
                    cdm-=cm;
                }else if(s[i-k+1]=='M'){
                    cm--;
                }
            }
            
        }
        cout<<ans<<'\n';
    }
}