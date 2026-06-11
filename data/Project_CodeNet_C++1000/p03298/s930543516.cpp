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

  map<pair<string,string>,int> mp;
  for(int i=0;i<(1<<n);i++){
    int now=i;
    string ft,bt;
    for(int j=0;j<n;j++){
      if((1<<j)&now){
        ft.push_back(s[n+j]);
      }else{
        bt.push_back(s[n+j]);
      }
    }
    reverse(ft.begin(),ft.end());
    reverse(bt.begin(),bt.end());
    mp[make_pair(ft,bt)]++;
  }

  ll ans=0;
  for(int i=0;i<(1<<n);i++){
    int now=i;
    string ft,bt;
    for(int j=0;j<n;j++){
      if((1<<j)&now){
        ft.push_back(s[j]);
      }else{
        bt.push_back(s[j]);
      }
    }
    ans=ans+mp[make_pair(ft,bt)];
  }

  cout<<ans<<endl;

  return 0;
}
