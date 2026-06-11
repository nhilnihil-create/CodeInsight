#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
  int n,m;
  cin >> n >> m;
  int use[m];
  rep(i,m){
    cin >> use[i];
    use[i]--;
  }
  sort(use,use+m);
  int a[9] = {2,5,5,4,5,6,3,7,6};
  vector<int> t(10005,-100000);
  t[0]=0;
  rep(i,n){
    for(auto k:use){
      if((i+1-a[k])>=0)t[i+1]=max(t[i+1],t[i+1-a[k]]+1);
    }
  }
  // rep(i,n+1){
  //   cout << t[i] << endl;
  // }
  int tmp=n;
  rep(i,t[n]-1){
    rep(j,m){
      if(t[tmp-a[use[m-j-1]]]==t[tmp]-1){
        cout << use[m-j-1]+1;
        tmp -= a[use[m-j-1]];
        break;
      }
    }
  }
  rep(j,m)if(tmp==a[use[m-j-1]]){
    cout << use[m-j-1]+1;
    break;
  }
  cout << endl;
  return 0;
}
