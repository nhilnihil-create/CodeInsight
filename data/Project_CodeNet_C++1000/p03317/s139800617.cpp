#include <bits/stdc++.h>
using namespace std;


int main(){
  

  int n,k;
  cin>>n>>k;
  
  int answer=0;
  
  int tmp=0;
  
  while (n-1>tmp){
    tmp+=k-1;
    answer++;
  }
  
  cout<<answer<<endl;
  
  

  
  

  
  
}