#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int aka=0;
  int ao=0;
  string S;
  cin>>S;
  for(int X=0;X<S.size();X++){
    if(S.at(X)=='0'){
      aka++;
    }
    else{
      ao++;
    }
  }
  int tou=min(ao,aka);
  cout<<tou*2<<endl;
}