#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int iti, juu, hyaku, sen;
  iti = N % 10;
  juu = (N / 10) % 10;
  hyaku = (N / 100) % 10;
  sen = N / 1000;
  if ((sen == hyaku && hyaku == juu) || (hyaku == juu && juu == iti)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}