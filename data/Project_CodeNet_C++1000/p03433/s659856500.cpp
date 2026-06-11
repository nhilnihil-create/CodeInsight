#include <bits/stdc++.h>
using namespace std;

int main() {
  int N , A;
  cin >> N >> A;
  int amari;
  amari = N % 500;
  if(amari <= A){
    cout << "Yes";
  }
  else{
    cout <<"No";
  }
}


