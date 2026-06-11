#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  double A=0;
  for(int i=0;i<N;i++){
    double S;
    string T;
    cin >> S >> T;
    if(T=="JPY"){
      A+=S;
    }
    else{
      A+=S*380000;
    }
  }
  cout << A << endl;
}   