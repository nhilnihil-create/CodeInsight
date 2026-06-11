#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M,X,mae=0,usiro=0;
  cin >> N >> M >> X;
  vector<int>vec(M);
  for(int i=0;i<M; i++){
    cin >> vec[i];
    if(vec[i]<X){
      mae++;
    }
    else{
      usiro++;
    }
  }
  cout << min(mae,usiro) << endl;
}

