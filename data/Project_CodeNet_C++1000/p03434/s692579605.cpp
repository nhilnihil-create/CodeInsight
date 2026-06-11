#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a=0;
  int b=0;
  vector<int> c(n);
  for(int i=0;i<n;i++){
      cin>>c[i];
  }
  sort(c.begin(),c.end());
  reverse(c.begin(),c.end());
  for(int i=0;i<n;i++){
      if(i%2==0) a+=c[i];
      else b+=c[i];
  }
  cout<<a-b<<endl;
}