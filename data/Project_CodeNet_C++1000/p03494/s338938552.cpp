#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  int a[200];
  int b =0;
  int i,j;
  int count=0;
  
  cin >> N ;
  
  for(i;i<N;i++){
   cin >> a[i];
  }
  j=0;
  while(b == 0){
   if(a[j]%2 == 1){
     b++;
   }else{
     a[j] = a[j]/2;
   }
    j++;
    if(j==N){
      j=0;
      count++;
    }
  }
  
    cout<<count<<endl;
}