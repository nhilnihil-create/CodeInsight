#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B;
  cin >> A >> B;
  string s;
  cin >> s;
  for(int i = 0; i <s.size(); i++){
    if(i == A){
      if(s.at(i)!='-'){
        cout << "No" << endl;
        return 0;
      }
    }
    else{
      if(s.at(i)<'0' || s.at(i)>'9'){
        cout << "No" << endl;
        return 0;
      } 
    }
    }
cout << "Yes" << endl;
}