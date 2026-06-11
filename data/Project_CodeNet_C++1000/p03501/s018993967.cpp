#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,A,B;
  int PLAN1,PLAN2;
  
  cin >> N >> A >> B;
  
  //プラン1,2の料金をそれぞれ計算
  PLAN1 = N * A;
  PLAN2 = B;
  
  if ( PLAN1 < PLAN2 ){
    cout << PLAN1 << endl;
  }
  else if(PLAN1 > PLAN2){
    cout << PLAN2 << endl;
  }
  else{
    cout << PLAN1 << endl;
  }
}