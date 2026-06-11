#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  int A ,b , c=100;
  for(int i=0 ; i<N ; i++){
    b=0 ;
    cin>>A;
    while(A%2==0&&A>0){
      
      A=A/2;
      b++;
    }
    c=min(c,b);  
  }
  cout<< c <<endl;
}
  