#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  vector<int>b(n);
  int i,j;
  for(i=0;i<n;i++)cin>>a[i];
  for(i=0;i<n;i++)cin>>b[i];
  i=0;
  j=0;
  long bstock = 0;
  for(i=0;i<n;i++){
    if(a[i]>=b[i]){
      bstock -= a[i]-b[i];
    }else{
      bstock += (b[i]-a[i])/2;
    }
  }
  if(bstock>=0)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
