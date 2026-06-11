#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

int main(){
  int N;
  cin>>N;
  if(N > 26){
    cout << 0 << endl;
    return 0;
  }
  vector<int> D(N);
  map<int,int> m;
  vector<int> base;
  base.push_back(0);
  for(int i(0);i<N;i++){
    cin>>D[i];
    m[D[i]]++;
    if(D[i] == 0){
      cout << 0 << endl;
      return 0;
    } else if(D[i] == 12){
      if(m[D[i]] == 2){
        cout << 0 << endl;
        return 0;
      }
      base.push_back(D[i]);
    } else if(m[D[i]] == 2){
      base.push_back(D[i]);
      base.push_back(24-D[i]);
    } else if(m[D[i]] >= 3){
      cout << 0 << endl;
      return 0;
    }
  }

  vector<int> p;
  for(auto mi:m){
    if(mi.second == 1 && mi.first != 0 && mi.first != 12) p.push_back(mi.first);
  }

  int num = int(p.size());
  int ans(0);
  for(int bit(0);bit<(1<<num);bit++){
    vector<int> kouho = base;
    int tmp(INFint);
    for(int i(0);i<num;i++){
      if (((bit>>i) & 1)){
        kouho.push_back(p[i]);
      }else{
        kouho.push_back(24-p[i]);
      }
    }
    for(int i(0);i<N+1;i++){
      for(int j(i+1);j<N+1;j++){
        int zisa = min(24 - abs(kouho[i]-kouho[j]),abs(kouho[i]-kouho[j]));
        tmp = min(tmp,zisa);
      }
    }
    ans = max(ans,tmp);
  }
  cout << ans << endl;
  return 0;
}
