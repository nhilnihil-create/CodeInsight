#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
  int N;
  cin>>N;
  int D[50];
  for(int i=0;i<N;i++) cin>>D[i];
  sort(D,D+N);
  int l=0;
  int r=0;
  int answer=12;
  for(int i=0;i<N;i++){
    if(l+D[i]<=D[i]-r){
      answer=min(answer,min(D[i]-r,24+l-D[i]));
      r=D[i];
    }
    else{
      answer=min(answer,min(l+D[i],24-D[i]-r));
      l=-D[i];
    }
  }
  cout<<answer<<endl;
  
  return 0;
}