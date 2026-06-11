#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  string s,t;
  cin >> s >> t;
  
  int n=s.size();
  vector<char> x(n),y(n);
  
  for(int i=0;i<n;i++){
    x[i]=s[i];
    y[i]=t[i];
  }
  
  for(int i=0;i<n;i++){
    char b=y[n-1];
    for(int j=n-2;j>=0;j--){
      y[j+1]=y[j];
    }
    y[0]=b;
    if(x==y){
      cout << "Yes" << endl;
      return 0;
    }
  }
  
  cout << "No" << endl;
  return 0;
}
