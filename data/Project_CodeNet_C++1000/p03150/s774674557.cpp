#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  string T ="keyence";
  for(int i = 0; i <T.size(); i++){//keyofscienceの時i=3で！
    if(S.at(i)!=T.at(i)){
      for(int j = 0; j<T.size()-i;j++){//0<=j<4
      if(S.at(S.size()-j-1)!=T.at(6-j)){
        cout << "NO" << endl;
        return 0;
      }
    }
    }
  }
  cout << "YES" << endl;

}