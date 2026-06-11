#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;
  cin>>n;
  vector<int> price(n);
  
  for (int i=0;i<n;i++){
    cin>>price.at(i);
  }
  
  sort(price.begin(),price.end());
  
  int answer=0;
  
  for (int i=0;i<n-1;i++){
    answer+=price.at(i);
  }
  
  answer+=price.at(n-1)/2;
  
  cout<<answer<<endl;
  
    

  
}
  











