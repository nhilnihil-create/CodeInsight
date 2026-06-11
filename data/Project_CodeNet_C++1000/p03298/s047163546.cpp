#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int n;
  string s;
  cin>>n;
  cin>>s;

  ll ans=0;
  map<pair<string,string>,ll> mp;
  for(int i=0;i<(1<<n);i++){
    int tmp=i,count=n;
    string v,w;
    while(count<2*n){
      if(tmp%2) v=v+s[count];
      else w=s[count]+w;
      count++;
      tmp/=2;
    }

    mp[make_pair(v,w)]++;
  }

  for(int i=0;i<(1<<n);i++){
    int tmp=i,count=0;
    string v,w;
    while(count<n){
      if(tmp%2) v=v+s[count];
      else w=s[count]+w;
      count++;
      tmp/=2;
    }

    ans+=mp[make_pair(w,v)];
  }

  cout<<ans<<endl;

  return 0;
}
