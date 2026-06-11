#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <time.h>
int main() {
  long P,Q,N,count,score,j,a,b;
  score=1.0;
  cin>>N>>P;
  Q=P+1;
  if(N==1){
cout<<P<<endl;
  }else{
  for(j=2;pow(j,N)<Q;j++){
  for(;;){
    
  if(fmod(P,pow(j,N))==0){
  P=P/pow(j,N);
    Q=P+1;
   score=score*j;
  } else{
    break;
  }
  
  }
  }
    cout<<score<<endl;
  }
  
   
}