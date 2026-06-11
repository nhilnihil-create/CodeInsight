#include <bits/stdc++.h>
using namespace std;

const int MOD=(int)1e9+7;

int main(){
  string S;
  cin >> S;

  long long h=1;
  vector<long long> abc(3,0);
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='A'){
      abc.at(0)+=h;
      abc.at(0)%=MOD;
    }
    else if(S.at(i)=='B'){
      abc.at(1)+=abc.at(0);
      abc.at(1)%=MOD;
    }
    else if(S.at(i)=='C'){
      abc.at(2)+=abc.at(1);
      abc.at(2)%=MOD;
    }
    else if(S.at(i)=='?'){
      long long a=abc.at(0)*3+h;
      long long b=abc.at(1)*3;
      long long c=abc.at(2)*3;
      abc.at(2)=c+abc.at(1);
      abc.at(1)=b+abc.at(0);
      abc.at(0)=a;
      abc.at(0)%=MOD;
      abc.at(1)%=MOD;
      abc.at(2)%=MOD;
      h*=3;
      h%=MOD;
    }
    //for(int j=0;j<3;j++)  cout << abc.at(j) << ",";cout << endl;
  }
  cout << abc.at(2) << endl;

  return 0;
}
