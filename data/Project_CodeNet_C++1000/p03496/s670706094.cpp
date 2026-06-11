#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
  int N,X,Y,Z,A,B,C,ans,b,max,min;
  cin >>N;
  int a[N];
  max=-100001;
  min=1000001;
  for(int i=0;i<N;i++){
  cin>>a[i];
  if(a[i]>max){
  max=a[i];
    C=i;
  }
      if(a[i]<min){
  min=a[i];
    A=i;
  }
  }
  if(abs(max)>abs(min)){
    cout<<2*N-1<<endl;
    for(int i=0;i<N;i++){
      cout<<C+1<<" "<<i+1<<endl;
    }
    if(a[C]<=0){
      for(int i=N-1;i>0;i--){
        cout<<i+1<<" "<<i<<endl;
      }
      return 0;
    }
    else{
            for(int i=0;i<N-1;i++){
        cout<<i+1<<" "<<i+2<<endl;
      }
      return 0;
    }
  }
  else {
    cout<<2*N-1<<endl;
    for(int i=0;i<N;i++){
      cout<<A+1<<" "<<i+1<<endl;
    }
        if(a[A]<=0){
      for(int i=N-1;i>0;i--){
        cout<<i+1<<" "<<i<<endl;
      }
      return 0;
    }
    else{
            for(int i=0;i<N-1;i++){
        cout<<i+1<<" "<<i+2<<endl;
      }
      return 0;
    }
  }
}
