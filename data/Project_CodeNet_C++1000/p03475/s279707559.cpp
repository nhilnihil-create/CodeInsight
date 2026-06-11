#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int n;
  cin >> n;
  vector<int> c(n-1),s(n-1),f(n-1);
  rep(i,n-1){
    cin >> c.at(i) >> s.at(i) >> f.at(i);
  }
  int i,j;
  rep(i,n-1){
    int ans=c.at(i)+s.at(i);
    for(j=i+1;j<n-1;j++){
      if(ans<=s.at(j)){
        ans=s.at(j)+c.at(j);
      }else{
        int p=(ans-s.at(j))%f.at(j);
        if(p==0){
          p=f.at(j);
        }
        ans=ans+(f.at(j)-p)+c.at(j);
      }
    }
    cout << ans << endl;
  }
  cout << 0;
}
    