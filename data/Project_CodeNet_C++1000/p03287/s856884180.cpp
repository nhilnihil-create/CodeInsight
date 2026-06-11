#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  long n,m;
  cin >> n >> m;
  long a[n];
  vector<long> mod;
  mod.push_back(0);
  long rui = 0;
  long ans = 0;
  rep(i,n){
    cin >> a[i];
    rui += a[i];
    mod.push_back(rui%m);
  }
  sort(mod.begin(), mod.end());
  long tmp = 1;
  rep(i,int(mod.size())-1){
    if(mod[i] == mod[i+1])tmp++;
    else{
      ans += (tmp*(tmp-1))/2;
      tmp = 1;
    }
  }
  ans += (tmp*(tmp-1))/2;
  cout << ans << endl;
  return 0;
}