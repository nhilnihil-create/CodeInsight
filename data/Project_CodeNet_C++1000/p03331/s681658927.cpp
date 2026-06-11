#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int sum_min=100;
  int sum_A=0;
  int sum_B=0;
  int A=0,B=0;
  for(int x=1; x<N; x++){
    A=x;
    B=N-x;
    sum_A=0;
    sum_B=0;
    //cout<<A<<" "<<B<<endl;
    for(int i=1; A+B>0; i++){
      sum_A+=A%10;
      A/=10;
      sum_B+=B%10;
      B/=10;
      //cout<<A<<" "<<B<<endl;
      //cout<<sum_A<<" "<<sum_B<<endl;
    }
    if(sum_A+sum_B<sum_min){
      sum_min=sum_A+sum_B;
      //cout<<sum_min<<endl;
    }
  }
  
  cout<<sum_min<<endl;
  return 0;
}
