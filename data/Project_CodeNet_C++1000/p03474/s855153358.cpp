#include <bits/stdc++.h>
using namespace std;

bool Check(char s){
    
    if(48 <= (int)s && (int)s <= 57) return true;
    else return false;
}
int main(void){
  
  int A,B;
  string S;
  cin >> A >> B >> S;

  if(S[A] != '-'){
      cout << "No" << endl; 
  } 
  else
  {
    int len = S.size();
      
    for(int i=0;i<len;i++){
        if(i != A && Check(S[i]) == false){
            cout  << "No" << endl; 
            return 0;
        }
    }
      
    cout << "Yes" << endl;
  }
  
}