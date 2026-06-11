#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int price = A * X + B * Y;
  int Z = max(X, Y);
  
  for(int i = 1; i <= Z; i++){
    if(min(X, Y) - i >= 0 ){
      if(price > A * (X - i) + B * (Y - i) + C * 2 * i) price =  A * (X - i) + B * (Y - i) + C * 2 * i;
    }else{
      if(Y - i < 0 && price > A * (X - i) + C * 2 * i) price =  A * (X - i) + C * 2 * i;
      if(X - i < 0 && price > B * (Y - i) + C * 2 * i) price = B * (Y - i) + C * 2 * i;
    }
  }
  cout << price;
}
