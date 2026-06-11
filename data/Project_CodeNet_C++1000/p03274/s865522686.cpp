#include <bits/stdc++.h>
using namespace std;


int main(){



  int n,k;
  cin>>n>>k;
  
  vector<int> x(n);
  
  for(int i=0;i<n;i++){
    int tmp;
    cin>>tmp;
    x.at(i)=tmp;
  }

  
  int answer=-1;
  
  if (x.at(0)>=0){
    answer=x.at(k-1)-0;

  }
  
  else if (x.at(n-1)<=0){
    answer=0-x.at(n-k);
  }
  
  else {
    int myindex;
    for (int i=0;i<n;i++){
      if (x.at(i)>=0){
        myindex=i;
        break;
      }
    }
    
    int minindex,maxindex;
    
    minindex=max(0,myindex-k);
    maxindex=min(n-k,myindex+1);
    
    for (int j=minindex;j<=maxindex;j++){
      int dis;
      
      int leftend;
      int rightend;
      
      leftend=x.at(j);
      rightend=x.at(j+k-1);
      
      if (leftend>=0){
        dis=rightend;
      
      }
      
      else if (rightend<=0){
        dis=0-leftend;
      }
      
      else {
        dis=min(abs(leftend),abs(rightend))+abs(leftend)+abs(rightend);
      }
      
      if (answer==-1){
        answer=dis;
      }
      
      else {
        answer=min(answer,dis);
      }
    }
  }
  

  
  cout<<answer<<endl;
  
                   
                                 
      
   
    
  
  
  

    
    
    

  
}