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
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int n,q;
string s;
vector<char> t(200010),d(200010);

bool left(int x){
  int now=x;
  rep(i,q){
    if(t[i]==s[now]){
      if(d[i]=='L') now--;
      else now++;
    }
    if(now==-1) return true;
    if(now==n) break;
  }
  return false;
} 

bool right(int x){
  int now=x;
  rep(i,q){
    if(t[i]==s[now]){
      if(d[i]=='L') now--;
      else now++;
    }
    if(now==n) return true;
    if(now==-1) break;
  }
  return false;
} 

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n>>q;
  cin>>s;
  rep(i,q) cin>>t[i]>>d[i];
  int high=n,low=-1,mid;
  int ans1,ans2;
  while(high-low>1){
    mid=(high+low)/2;
    if(left(mid)) low=mid;
    else high=mid;
  }
  ans1=low;
  high=n,low=-1;
  while(high-low>1){
    mid=(high+low)/2;
    if(right(mid)) high=mid;
    else low=mid;
  }
  ans2=high;
  //cout<<ans1<<' '<<ans2<<endl;
  if(ans1>=ans2) cout<<0<<endl;
  else{
    cout<<ans2-ans1-1<<endl;
  }
}