#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X;
  int a,b,c,count = 0;
  cin >> A >> B >> C >> X;

  a = 500;
  b = 100;
  c = 50;

  for(int i =0;i <= A;i++){
    for(int j = 0;j <= B;j++){
      for(int k = 0;k <= C;k++){
        if(X == a*i+b*j+c*k){
          count += 1;
        }
      }
    }
  }
cout << count << endl;
  return 0;
}