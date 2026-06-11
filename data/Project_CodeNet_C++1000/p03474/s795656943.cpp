#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  string S;
  cin >> A >> B >> S;
  
  string ans = "Yes"; 
  for(int i=0; i<A+B+1; i++){
    if(i==A && S.at(i)!='-')ans="No";
    if(i!=A && S.at(i)=='-')ans = "No";
  }
  
  cout << ans << endl;
}