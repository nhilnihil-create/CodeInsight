#include <bits/stdc++.h>
using namespace std;

int main() {
  int N=0, Si=0, Sj=0, Sk=0, Sl=0;
  string S;
  cin >> N;

  for(int m=0; m<N; m++){
    cin >> S;
    if( S == "P"){
      Si++;
    }
    else if( S == "W"){
      Sj++;
    }
    else if( S == "G"){
      Sk++;
    }
    else {
      Sl++;
    }
  }
  
  if(Si>0 && Sj>0 && Sk>0 && Sl>0){
    cout << "Four" << endl;
  }
  else{
   cout << "Three" << endl;
  } 
}