#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin>>n;
  vector<int>value(n);
  vector<int>cost(n);
  for(int i;i<n;i++){
    cin>>value.at(i);
  }
  for(int i;i<n;i++){
    cin>>cost.at(i);
  }
  int sum=0;
  for(int i;i<n;i++){
    if(value.at(i)>cost.at(i)){
      sum+=value.at(i)-cost.at(i);
    }
  }
  cout<<sum<<endl;
  

}