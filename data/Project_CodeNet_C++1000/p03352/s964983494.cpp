#include<bits/stdc++.h>
using namespace std;
int main(){
  int x;
  cin >> x;
  long long int minimum = -99999;
  for (int i = 1; i <= 40; i++){
    for (int j = 2; j <= 12; j++){
      if (std::pow(i,j) <= x){
        if (std::pow(i,j) > minimum){
          minimum = std::pow(i,j);
        }
      }
    }
  }
  cout << minimum << endl;
}