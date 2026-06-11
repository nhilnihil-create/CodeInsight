#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  string S;
  bool aBool=true;
  cin >> A >> B >> S ;
 if( S[A] == '-' && S.size()==A+B+1){
   S.erase(A,1);
   for(int count=0;
       count<A+B;
       count++){
   aBool=S[count]!='-'&&aBool;
   } 
 }
  else{
aBool=false;
}
   if(aBool){
   cout << "Yes" << endl;
   }
  else{
  cout << "No" << endl;
  }
}