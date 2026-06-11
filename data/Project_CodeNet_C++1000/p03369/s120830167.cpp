#include<bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;
  
  int ramen = 700;
  
  if(N[0] == 'o'){
    ramen += 100;
  }
  
  if(N[1] == 'o'){
    ramen += 100;
  }
  
  if(N[2] == 'o'){
    ramen += 100;
  }
  
  cout << ramen <<endl;
}