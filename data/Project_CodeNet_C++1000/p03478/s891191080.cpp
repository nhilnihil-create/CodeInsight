#include <bits/stdc++.h>
using namespace std;

int main() {
  //1以上N以下の整数のうち、10進法での各桁の和がA以上B以下であるものの総和を求めてください。
  
  int N,A,B;
  cin >> N >> A >> B;
  
  int SUM = 0;       //総和
  int digitSUM;      //各桁の和
  
  for(int i = 1; i <= N; i++){
    
    digitSUM = 0;
    
    //各桁の和を算出
    digitSUM = (i / 10000) + ((i % 10000) / 1000) + ((i % 1000) / 100) + ((i % 100) / 10) + (i % 10);

    if (digitSUM >= A && digitSUM <= B){
      SUM = SUM + i;
    }
  }
  
  cout << SUM << endl;
  
}
  
 