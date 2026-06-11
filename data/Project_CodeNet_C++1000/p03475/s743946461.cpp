#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  int n;
  cin>>n;
  vector<int> c(n-1),s(n-1),f(n-1);
  rep(i,n-1){
    cin>>c[i]>>s[i]>>f[i];
  }
  vector<int> ans(n);
  for(int i = 0; i < n-1; i++){
    int now=0;
    for(int j = i; j < n-1; j++){
      if(now < s[j]) now+=s[j]-now;
      else if(now%f[j]!=0) now+=f[j]-now%f[j];
      now += c[j];
    }
    ans[i] = now;
  }
  rep(i,n){
    cout<<ans[i]<<endl;
  }
}
