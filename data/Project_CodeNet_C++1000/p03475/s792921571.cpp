#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  int n;
  cin >> n;
  vector<int> c(n-1),s(n-1),f(n-1);
  for(int i=0;i<n-1;++i){
    cin >> c[i] >> s[i] >> f[i];
  }
  for(int i=0;i<n-1;++i){
    ll ti=c[i]+s[i];
    for(int j=i+1;j<n-1;++j){
      if(ti<s[j]){
        ti=s[j];
      }else if(ti%f[j]==0);
      else ti=ti+f[j]-ti%f[j];
      ti+=c[j];
    }
    cout << ti << endl;
  }
  cout << "0" << endl;
  return 0;
}
