#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
 
int main(){
  string S;
  cin >> S;
  if(S.at(0)=='a' && S.at(1)=='b' && S.at(2)=='c'){
    cout << "Yes" << endl;
  }
  else if(S.at(0)=='a' && S.at(1)=='c' && S.at(2)=='b'){
    cout << "Yes" << endl;
  }
  else if(S.at(0)=='b' && S.at(1)=='a' && S.at(2)=='c'){
    cout << "Yes" << endl;
  }
  else if(S.at(0)=='b' && S.at(1)=='c' && S.at(2)=='a'){
    cout << "Yes" << endl;
  }
  else if(S.at(0)=='c' && S.at(1)=='b' && S.at(2)=='a'){
    cout << "Yes" << endl;
  }
  else if(S.at(0)=='c' && S.at(1)=='a' && S.at(2)=='b'){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
  
  
  
  
