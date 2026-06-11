#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
  string s;
  cin >> s;
  if(s.substr(0,2) =="00" || s.substr(2,2) =="00"){
    if(s=="0000"){
      cout << "NA" << endl;
      return 0;
    }
    else if(s.substr(0,2) =="00" && s.substr(2,2) <="12"){
      cout << "YYMM" << endl;
      return 0;
    }
    else if(s.substr(0,2) <="12" && s.substr(2,2) =="00"){
      cout << "MMYY" << endl;
      return 0;
    }
    else cout << "NA" << endl;
    return 0;
  }


  if(s.substr(0,2) <="12" && s.substr(2,2) <="12"){
    cout << "AMBIGUOUS" << endl;
    return 0;
  }
  else if(s.substr(0,2) <="12"){
    cout << "MMYY" << endl;
    return 0;
  }
  else if(s.substr(2,2) <="12"){
    cout << "YYMM" << endl;
    return 0;
  }
  else{
    cout << "NA" << endl;
    return 0;
  } 
}
