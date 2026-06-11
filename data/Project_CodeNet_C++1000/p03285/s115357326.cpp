#include <bits/stdc++.h>
using namespace std;

const int Nmax = 100;
const int cake = 4;
const int donut = 7;

int main(){

  int N;
  cin >> N;

bool flag = false;

  for(int i = 0; i < Nmax/cake; ++i){
    for(int j = 0; j < Nmax/donut; ++j){
        if(cake * i + donut * j == N) flag = true;
    }
  }

  if(flag == true) cout << "Yes";
  else cout << "No";


  return 0; 
}