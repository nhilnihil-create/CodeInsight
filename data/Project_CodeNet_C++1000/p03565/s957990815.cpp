#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	string S1,S2;
  int sw = 0;
  cin >> S1 >> S2;
  if(S1.length() < S2.length()){
	cout << "UNRESTORABLE" << endl;
    return 0;
  }
  int count = 0;
  for(int i = S1.length() - S2.length();i >= 0;i--){
    sw = 0;
    string s = S1.substr(i,S2.length());
    for(int j = 0;j < S2.length();j++){
      if(!(s[j] == '?' || s[j] == S2[j])){
		sw = 1;
        break;
      }
    }
    if(sw == 0){
      for(int j = 0;j < S2.length();j++){
        S1[i + j] = S2[j];
      }
      break;
    }
      
  }
  if(sw == 1){
	cout << "UNRESTORABLE" << endl;
    return 0;
  }
  froop1(0,S1.length()){
	if(S1[i] == '?'){
		S1[i] = 'a';
    }
  }
  cout << S1 << endl;
      
    
}