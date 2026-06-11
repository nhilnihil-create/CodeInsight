#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, T;
  cin >> N >> T;
  int c, t;
  int Ans=10000; 
  for(int i=0; i<N; i++){
    cin >> c >> t;
    if(t<=T){
      Ans=min(Ans, c);
    }
  }
  if(Ans<10000){
    cout << Ans << endl;
  }
  else{
    cout << "TLE" << endl;
  }
}
