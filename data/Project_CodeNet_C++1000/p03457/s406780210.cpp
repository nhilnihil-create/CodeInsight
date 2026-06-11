#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int>t(n),x(n),y(n);
  for(int i=0;i<n;i++)cin>>t[i]>>x[i]>>y[i];
  int tmp_t=0;
  int tmp_x=0;
  int tmp_y=0;
  for(int i=0;i<n;i++){  
    if(t[i]-tmp_t<abs(x[i]+y[i]-tmp_x-tmp_y)){
      cout<<"No"<<endl;
      return 0;
    }
    if((t[i]-x[i]-y[i])%2==1){
      cout<<"No"<<endl;
      return 0;
    }
    tmp_t=t[i];
    tmp_x=x[i];
    tmp_y=y[i];
  }
  cout<<"Yes"<<endl;
  return 0;
}