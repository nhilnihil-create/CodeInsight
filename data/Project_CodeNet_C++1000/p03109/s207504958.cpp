#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  string T=S.substr(5,2);
  if(T=="01" || T=="02" || T=="03" || T=="04"){
    cout << "Heisei" << endl;
  }
  else{
    cout << "TBD" << endl;
  }
}
    