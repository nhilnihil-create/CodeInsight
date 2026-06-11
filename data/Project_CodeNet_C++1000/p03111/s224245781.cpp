#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

vector<int> num;
vector<int> l(8),g(3);
int ans = mod;

void SomeBit(int n,int k,const int m){
  if(k == 0){
    vector<int> result(n,0);
    vector<int> cnt(n,0);
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        if(num[i] == j){
          result[j] += l[i];
          cnt[j]++;
        }
      }
    }
    int now = 0;
    for(int i = 0; i < n; i++){
      if(cnt[i] == 0){
        return;
      }
      now += abs(g[i]-result[i]);
      now += (cnt[i]-1)*10;
    }
    ans = min(ans,now);
    return;
  }

  for(int i = 0; i <= n; i++){
    num.push_back(i);
    SomeBit(n,k-1,m);
    num.pop_back();
  }

  return;
}


int main(){
  int n;
  cin >> n;
  for(int i = 0; i < 3; i++) cin >> g[i];
  for(int i = 0; i < n; i++) cin >> l[i];
  SomeBit(3,n,n);
  cout << ans << endl;
  return 0;
}