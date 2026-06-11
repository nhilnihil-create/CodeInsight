#include <bits/stdc++.h>
using namespace std;


int main(){
  

  int n;
  cin>>n;
  
  vector<long long> data(n);
  
  for (int i=0;i<n;i++){
    long long tmp;
    cin>>tmp;
    
    data.at(i)=tmp-i;
  }
  
  sort(data.begin(),data.end());
  
  int b=data.at(n/2);
  
  long long answer=0;
  
  for (int i=0;i<n;i++){
    answer+=abs(data.at(i)-b);
  }
  
  cout<<answer<<endl;
  
  

  
  

  
  
}