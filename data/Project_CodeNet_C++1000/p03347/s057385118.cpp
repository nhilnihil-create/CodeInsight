#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
#define pb push_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
#define elif else if
#define se second
#define fi first
typedef long long ll;
typedef multiset<ll> S;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll,vector<ll>,greater<ll>> SPQ;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
const ll inf=1001001001001001;
const int INF=1001001001;
const ll mod=1000000007;
bool chmin(auto &a,auto b){if(a>b){a=b;return true;}return false;}
bool chmax(auto &a,auto b){if(a<b){a=b;return true;}return false;}

int main(){
    ll n;cin>>n;
    vi v(n);
    ll ans=0;
    rep(i,n)cin>>v[i];
    if(v[0]!=0){
        cout<<-1<<endl;
        return 0;
    }
    for(ll i=n-1;i>0;i--){
        ans+=v[i];
      	if(v[i]<0){
        	cout<<-1<<endl;
        	return 0;
      	}
        rep(j,v[i]-1){
            if(i-j-1<0){
                cout<<-1<<endl;
                return 0;
            }
            if(v[i-j-1]<=v[i]-j-1)v[i-j-1]-=v[i]-j-1;
          	else break;
          	if(v[i-j-1]<0){
            	cout<<-1<<endl;
            	return 0;
            }
        }
    }
    cout<<ans<<endl;
}
