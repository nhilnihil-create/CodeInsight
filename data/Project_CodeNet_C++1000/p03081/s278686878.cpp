#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define is(a, b) a == b
#define len(v) ll(v.size())

//vector書き出し
template <class T>
void cout_vec(const vector<T> &vec1){
  rep(i,len(vec1)){
    cout<<vec1[i]<<' ';
  }
  cout<<'\n';
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;

int n,q;
string s;
vector<char> t(200010),d(200010);

bool left(int x){
  int now=x;
  rep(i,q){
    if(s[now]==t[i]){
      if(d[i]=='L') now--;
      else now++;
    }
    if(now==-1) return true;
  }
  return false;
}

bool right(int x){
  int now=x;
  rep(i,q){
    if(s[now]==t[i]){
      if(d[i]=='L') now--;
      else now++;
    }
    if(now==n) return true;
  }
  return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>q>>s;
    rep(i,q) cin>>t[i]>>d[i];
    int low=0,high=n,mid;
    while(high-low>1){
      mid=(low+high)/2;
      if(left(mid)) low=mid;
      else high=mid;
    }
    int low2=0,high2=n,mid2;
    while(high2-low2>1){
      mid2=(low2+high2)/2;
      if(right(mid2)) high2=mid2;
      else low2=mid2;
    }
    if(low>=high2) cout<<0<<endl;
    else cout<<n-(low+1)-(n-high2)<<endl;
}
