#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;i++) cin >> a[i];

  map<ll,int> mp;
  for(int i=0;i<n;i++){
    auto itr = mp.find(a[i]);
    if(itr != mp.end()){
      itr->second++;
    }else{
      mp.insert(make_pair(a[i],1));
    }
  }

  ll cnt = 0;
  for(auto itr=mp.begin();itr!=mp.end();itr++){
    if(itr->first < itr->second){
      cnt += itr->second - itr->first;
    }else if(itr->first > itr->second){
      cnt += itr->second;
    }
  }

  cout << cnt << endl;
}
