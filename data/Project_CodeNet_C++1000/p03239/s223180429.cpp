#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,T;
  cin >> N >> T;
  int mincost=10000;
  for(int i=0;i<N;i++){
    int A,B;
    cin >> A >> B;
    if(B<=T){
      mincost=min(mincost,A);
    }
  }
  if(mincost==10000){
    cout << "TLE" << endl;
  }
  else{
    cout << mincost << endl;
  }
}