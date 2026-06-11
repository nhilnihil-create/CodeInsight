#include <bits/stdc++.h>
using namespace std;


int main(){
  
  
  int n;
  cin>>n;

  string s;
  cin>>s;
  

  vector<int> data(n);
  
  int eastcount=0;
  
  for (int i=0;i<n;i++){
    if (s.at(i)=='E'){
      eastcount++;
    }
    data.at(i)=eastcount;
  }
  
  int answer=data.at(n-1)-data.at(0);
  
  for (int i=1;i<n;i++){
    int tmp=i-data.at(i-1)+data.at(n-1)-data.at(i);
    answer=min(answer,tmp);
  }
  
  cout<<answer<<endl;
  
    
    

  
  

  
  
}