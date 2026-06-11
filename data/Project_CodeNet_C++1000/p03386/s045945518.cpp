#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B,N;
  cin >> A >> B >> N;
  if(B-A+1 >= 2*N){
    for(int i= 0; i < N ; i++){
      cout << A+i <<endl;;
    }
    for(int i= N-1 ; i>-1 ; i--){
      cout << B-i << endl;
    }
  }
    else{
      for(int i = A; i <B+1 ; i++){
        cout << i << endl;
      }
    }

}