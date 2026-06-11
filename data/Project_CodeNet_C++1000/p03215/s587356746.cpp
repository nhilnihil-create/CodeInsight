#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<'\n';
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n+1),sum(n+1,0),b;
    FOR(i,1,n+1){
      cin>>a[i];
      sum[i]=sum[i-1]+a[i];
    }
    FOR(i,1,n+1)FOR(j,i,n+1){
      b.push_back(sum[j]-sum[i-1]);
    }
    ll ans=0;
    ll m=len(b);
    bool flag=false;
    vector<bool> ch(m,false);
    for(ll i=50;i>=0;i--){
      ll cnt=0;
      ll now=(1LL<<i);
      rep(j,m){
        if(flag){
          if(ch[j]&&(b[j]&now)) cnt++;
        }else{
          if((b[j]&now)) cnt++;
        }
      }
      if(cnt>=k){
        if(flag){
          rep(j,m){
            if(ch[j]&&!(b[j]&now)) ch[j]=false;
          }
        }else{
          rep(j,m) if(b[j]&now) ch[j]=true;
          flag=true;
        }
        ans+=now;
        //cout<<i<<' '<<now<<' '<<cnt<<' '<<ans<<endl;
      }
      //cout<<i<<' '<<(1<<i)<<' '<<cnt<<' '<<ans<<endl;
    }
    cout<<ans<<endl;
}