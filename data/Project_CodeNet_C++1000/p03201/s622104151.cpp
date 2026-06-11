#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define INF 3000000000
using namespace std;
typedef long long ll;
int main(){
  ll n,val,tmp,m,ans=0;
  cin >> n;
  ll a[n];
  map<ll,ll> mp;
  vector<ll> list;
  bool can;
  for(ll i=2;i<INF;i*=2){
    list.push_back(i);
  }
  m = list.size();
  for(int i=0;i<n;i++){
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(a,a+n);
  for(int i=n-1;i>=0;i--){
    val=a[i];
    can=false;
    if(mp.find(val)==mp.end()){
      continue;
    }
    mp[val]--;
    if(mp[val]==0){
      mp.erase(val);
    }
    for(int j=m-1;j>=0;j--){
      tmp = list[j]-val;
      if(mp.find(tmp)!=mp.end()){
        can=true;
        break;
      }
    }
    if(can){
      ans++;
      mp[tmp]--;
      if(mp[tmp]==0){
        mp.erase(tmp);
      }
    }
  }
  cout << ans << endl;
}
