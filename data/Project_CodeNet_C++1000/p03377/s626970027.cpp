#include <bits/stdc++.h>
using namespace std;

int main() {
  int cat,mix,hopeCat;
  string chk = "NO";
  
  cin >> cat >> mix >> hopeCat;
  
  if(cat == hopeCat){
    chk = "YES";
  }else if(cat < hopeCat){
    if(cat + mix >= hopeCat) chk = "YES";
  }
  
  cout << chk;
}
