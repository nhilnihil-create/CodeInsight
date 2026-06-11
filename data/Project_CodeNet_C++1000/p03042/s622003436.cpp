#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  bool mmyy = stoi(S.substr(0, 2)) <= 12 && stoi(S.substr(0, 2)) != 0;
  bool yymm = stoi(S.substr(2, 2)) <= 12 && stoi(S.substr(2, 2)) != 0;
  if(mmyy && yymm){
    cout << "AMBIGUOUS" << endl;
  }else if(mmyy){
    cout << "MMYY" << endl;
  }else if(yymm){
    cout << "YYMM" << endl;
  }else{
    cout << "NA" << endl;
  }
}