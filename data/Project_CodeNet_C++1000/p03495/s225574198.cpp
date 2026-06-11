#include <bits/stdc++.h>
using namespace std;





int main(){
  



  int n,k;
  cin>>n>>k;
  
  vector<int> data(n);
  
  for (int i=0;i<n;i++){
    int tmp;
    cin>>tmp;
    data.at(i)=tmp;
  }
  
  
  vector<int> count(200001,0);
  
  for (int i=0;i<n;i++){
    count.at(data.at(i))++;
  }
  
  sort(count.begin(),count.end());
  
  int plusindex;
  
  for (int i=0;i<=200000;i++){
    if (count.at(i)>0){
    plusindex=i;
      break;
    }
  }
  
  int kinds=200000-plusindex+1;
  
  int answer=0;
  
  if (kinds<=k){
    answer=0;
  }
  
  else {
    for (int i=plusindex;i<=200000-k;i++){
      answer+=count.at(i);
    }
  }
  
  cout<<answer<<endl;
  
    
    
  
    
    
    

      
  
    

  
  
    
  
  
  
}