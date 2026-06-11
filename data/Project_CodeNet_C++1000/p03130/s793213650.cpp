#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<pair<int, int>> P(3);
  int A, B;
  for(int i=0; i<3; i++){
    cin >> A >> B;
    if(A>B){
      P.at(i)=make_pair(B, A);
    }
    else{
      P.at(i)=make_pair(A, B);
    }
  }
  sort(P.begin(), P.end());
  int Now=1;
  if(P.at(0).first!=1){
    cout << "NO" << endl;
  }
  else if(P.at(0).second==2){
    if(P.at(1).first==2 && (P.at(1).second==3 || P.at(1).second==4) && P.at(2).first==3 && P.at(2).second==4){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
  else if(P.at(0).second==3){
    if(P.at(1).first==2 && ((P.at(1).second==3 && P.at(2).first==2 && P.at(2).second==4) || P.at(1).second==4)){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
  else{
    if(P.at(1).second!=4){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  } 
}