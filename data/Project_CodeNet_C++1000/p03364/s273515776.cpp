#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll n,ans=0;
  bool is_s;
  char tmp;
  cin >> n;
  string s[n];
  for(int i=0;i<n;i++){
    cin >> s[i];
  }
  for(int k=0;k<n;k++){
    is_s=true;
    for(int i=0;i<n;i++){
      for(int j=i;j<n;j++){
        if(s[i][j]!=s[j][i]){
          is_s=false;
          break;
        }
      }
      if(!is_s){
        break;
      }
    }
    if(is_s){
      ans+=n;
    }
    for(int i=0;i<n;i++){
      tmp = s[i][0];
      for(int j=0;j<n-1;j++){
        s[i][j]=s[i][j+1];
      }
      s[i][n-1]=tmp;
    }
  }
  cout << ans << endl;
}
