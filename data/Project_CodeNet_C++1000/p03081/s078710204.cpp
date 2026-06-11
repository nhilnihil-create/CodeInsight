#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define fi first
#define se second
#define INF 1000000009
#define LLINF 1000000000000000009LL
using ll = long long;
using P = pair<char, char>;

int main(){
  int n,q;
  string s;
  cin>>n>>q>>s;
  vector<P>a(q);
  rep(i,q){
    cin>>a[i].fi>>a[i].se;
  }

  auto judge=[&](ll mid){
    int now=mid;
    rep(i,q){
      if(s[now]==a[i].fi){
        if(a[i].se=='L')now--;
        else now++;
      }
      if(now<0)return false;
      if(now>=n)return true;
    }
    return true;
  };
  auto bs=[&](){
    ll l=-1,r=n;
    while(r-l>1){
      ll mid=(l+r)/2;
      if(judge(mid)){
        r=mid;
      }
      else{
        l=mid;
      }
    }
    return r;
  };

  auto judge2=[&](ll mid){
    int now=mid;
    rep(i,q){
      if(s[now]==a[i].fi){
        if(a[i].se=='L')now--;
        else now++;
      }
      if(n<=now)return false;
      if(now<0)return true;
    }
    return true;
  };
  auto bs2=[&](){
    ll l=-1,r=n;
    while(r-l>1){
      ll mid=(l+r)/2;
      if(judge2(mid)){
        l=mid;
      }
      else{
        r=mid;
      }
    }
    return l;
  };
  int nl=bs();
  int nr=n-bs2()-1;
  cout<<n-nl-nr<<endl;
  return(0);
}
