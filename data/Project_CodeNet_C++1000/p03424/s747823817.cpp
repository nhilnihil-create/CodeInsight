#include<bits/stdc++.h>
using namespace std;
#define REP(i,N) for(int (i)=0;(i)<(N);(i)++)
#define FOR (i,m,n) for(int (i)=m;(i)<(n);(i)++)

int main(){
  int num;
  string spc;
  bool y=0;
  cin >> num;
  
  REP(i,num){
    cin >> spc;
    if(spc == "Y"){
      y=1;
      cout << "Four" << endl;
      break;
    }
    if(i==(num-1))cout << "Three" << endl;
  }
}