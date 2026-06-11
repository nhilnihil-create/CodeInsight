#include <bits/stdc++.h>
using namespace std;

int main(){
  int Ndet0,Ndet1,Ntox1;
  cin >> Ndet0 >> Ndet1 >> Ntox1;
  
  int ans= (Ndet0+ Ndet1 >= Ntox1) ? Ndet1+ Ntox1
                                   : Ndet1+ (Ndet0+ Ndet1)+ 1;

  cout << ans << endl;
}