#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  int i = 0;
  int sum = 0;
  
  cin >> A >> B;
  
  for(i = A ; i <= B; i++){
    int a,b,c,d,e;
    
    //1の桁の値
    a = i % 10;
    //10の桁の値
    b = (i % 100 - a) / 10;
    //100の桁の値
    c = (i % 1000 - 10 * b - a) / 100;
    //1000の桁の値
    d = (i % 10000 - 100 * c - 10 * b - a) / 1000;
    //10000の桁の値
    e = (i % 100000 - 1000 * d - 100 * c -10 * b - a) / 10000;
    
    if (a == e && b == d){
      sum++;
    }
  }
  cout << sum << endl;
}
