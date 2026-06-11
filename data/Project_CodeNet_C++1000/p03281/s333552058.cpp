#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(){
  int N; cin>>N;
  int L=0;
  int Ans=0;
  for(int i=1; i<N+1; i+=2){
   for(int j=1; j<i+1; j++){
     if(i%j==0)
       L++;
     else continue;
   }
    if(L==8)
      Ans++;
    L=0;
  }
  cout<<Ans<<endl;
}
