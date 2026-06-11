#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  string A={};
  A.push_back(S.at(6));
  if(S.at(5)=='1' || stoi(A)>4){
    cout << "TBD" << endl;
  }
  else{
    cout << "Heisei" << endl;
  }
}