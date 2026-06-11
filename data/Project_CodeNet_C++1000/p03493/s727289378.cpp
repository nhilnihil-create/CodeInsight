#include <bits/stdc++.h>
using namespace std;

int main() {
  int S;
  cin >> S ;
  int Hyaku , Ju , Ichi ;
  Hyaku = S / 100 ;
  S = S % 100 ;
  Ju = S / 10 ;
  S = S % 10 ;
  Ichi = S ;
  cout << Hyaku + Ju + Ichi << endl;
}
