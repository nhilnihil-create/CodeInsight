#include<bits/stdc++.h>
using namespace std;
int main(){
  double n;
  cin>>n;
  double sideAngle = 360/n;
  double sum = 0;
  for(int i=0;i<n;i++){
    sum+=(180.0-sideAngle);
  //  cout<<sum<<endl;
  }

  cout<<sum<<endl;
  return 0;
}
