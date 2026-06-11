#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int>vec(5);
  cin >> vec[0] >> vec[1] >> vec[2] >> vec[3] >> vec[4];
  vector<int>amari(5);
  for(int i=0; i<5; i++){
    amari[i] = 10-(vec[i]%10);
    if(amari[i] == 10){
      amari[i] -= 10;
    }
  }
  sort(amari.begin(),amari.end());
  cout << vec[0]+vec[1]+vec[2]+vec[3]+vec[4]+amari[0]+amari[1]+amari[2]+amari[3] << endl;
}
