#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const ll p=1000000007;
int main(){
  int n;
  cin >> n;
  int ans=1000000000;
  rep(i,n/9+1){
    int o=i*9;
    int u=n-o;
    int l=0;
    while(o){
      l+=o%9;
      o/=9;
    }
    while(u){
      l+=u%6;
      u/=6;
    }

    ans=min(ans,l);
  }
  cout << ans << endl;
}
