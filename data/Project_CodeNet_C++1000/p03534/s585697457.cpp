#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

int main(){
  string s;
  cin>>s;
  int c[3]={};
  for(int i=0;i<s.size();i++){
    c[s[i]-'a']++;
  }
  int m=min({c[0],c[1],c[2]});
  c[0]-=m,c[1]-=m,c[2]-=m;
  if(max({c[0],c[1],c[2]})<2)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
