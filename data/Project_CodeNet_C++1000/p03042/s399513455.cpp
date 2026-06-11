#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  string s;
  cin >> s;

  int s1, s2;

  s1 = stoi(s.substr(0,2));
  s2 = stoi(s.substr(2,2));
  if(1<=s1 && s1<=12){
    if(1<=s2 && s2<=12) cout << "AMBIGUOUS" << endl;
    else cout << "MMYY" << endl;
  }
  else{
    if(1<=s2 && s2<=12) cout << "YYMM" << endl;
    else cout << "NA" << endl;
  }

}