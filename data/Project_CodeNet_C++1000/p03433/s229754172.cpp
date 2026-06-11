#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, A;
  cin >> N >> A;
  int amari;
  amari = N / 500;
  int nokori;
  nokori = N - 500 * amari;
  if(nokori<=A){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}