#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int dis(P x,P y){
  return abs(x.first-y.first)+abs(x.second-y.second);
}

int main(){
  int n;
  cin>>n;
  ll a[5]={0,0,0,0,0};
  rep(i,0,n){
    string s;
    cin>>s;
    if(s[0]=='M'){
      a[0]++;
    }
    if(s[0]=='A'){
      a[1]++;
    }
    if(s[0]=='R'){
      a[2]++;
    }
    if(s[0]=='C'){
      a[3]++;
    }
    if(s[0]=='H'){
      a[4]++;
    }
  }
  ll ans=0;
  ans+=a[0]*a[1]*a[2];
  ans+=a[0]*a[1]*a[3];
  ans+=a[0]*a[1]*a[4];
  ans+=a[0]*a[2]*a[3];
  ans+=a[0]*a[2]*a[4];
  ans+=a[0]*a[3]*a[4];
  ans+=a[1]*a[2]*a[3];
  ans+=a[1]*a[2]*a[4];
  ans+=a[1]*a[3]*a[4];
  ans+=a[2]*a[3]*a[4];
  cout<<ans<<endl;
}