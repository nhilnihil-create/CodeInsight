#include <bits/stdc++.h>
using namespace std;

int main(){
 int N;
 cin>>N;
 
 vector<int>d(N);
  for(int i=0;i<N;i++){
    cin>>d.at(i);
  }
 
  int i=0,j=100,k=0;
  while(j>0){
    
   while(i<N){
     if(d.at(i)==j){
       k++;
       break;
     }
     else{
       i++;
     }
   }
    i=0;
    j--;
  }
  cout<<k<<endl;
}