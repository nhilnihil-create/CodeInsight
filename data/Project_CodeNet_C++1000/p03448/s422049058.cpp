#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X,N;
  int sum = 0;
  cin >> A >> B >> C >> X;
  for(int n=0;n<=A;n++){
    for(int m=0;m<=B;m++){
      for(int k=0;k<=C;k++){
        if(n*500+m*100+k*50==X){
          sum++;
        }
      }
    }
  }
  cout << sum << endl;
}
