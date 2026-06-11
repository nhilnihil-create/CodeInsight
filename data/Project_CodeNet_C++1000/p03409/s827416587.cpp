#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main() {
  int n;
  cin>>n;
  vector<P>a,b;
  rep(i,n){
    int s,t;
    cin>>s>>t;
    a.push_back(P(s,t));
  }
  rep(i,n){
    int s,t;
    cin>>s>>t;
    b.push_back(P(s,t));
  }
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  int ans=0;
  vector<bool>ch(n);
  rep(i,n){
    int now=1001001001;
    int co=-1;
    rep(j,n){
      if(!ch[j]&&a[i].first<b[j].first&&a[i].second<b[j].second){
        if(now>b[j].second){
          now=b[j].second;
          co=j;
        }
      }
    }
    if(co>=0){
      ans++;
      ch[co]=true;
    }
  }
  
  cout<<ans<<endl;
}

