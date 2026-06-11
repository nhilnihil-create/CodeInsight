#include<bits/stdc++.h>
using namespace std;

int main(){
int N,A,B;
  cin >> N >> A >>B;
int count_1,count_2,count_3,count_min;
  count_1=0;
  count_2=0;
  count_3=0;
  
  for(int i=0;i<N;i++){
      int X;
    cin >>X;
     if(X<A+1){
     count_1++;
     }
     else if(A<X && X<B+1){
     count_2++;
     }
     else if(B<X){
     count_3++;
     }
  }
  
  count_min=min(count_1,(min(count_2,count_3))); 
  cout<< count_min<<endl;
}
