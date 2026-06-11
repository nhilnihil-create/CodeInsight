#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> M(5, 0);
  for(int i=0; i<N; i++){
    string S;
    cin >> S;
    if(S.at(0)=='M'){
      M.at(0)++;
    }
    if(S.at(0)=='A'){
      M.at(1)++;
    }
    if(S.at(0)=='R'){
      M.at(2)++;
    }
    if(S.at(0)=='C'){
      M.at(3)++;
    }
    if(S.at(0)=='H'){
      M.at(4)++;
    }
  }
  int64_t Ans=0;
  for(int i=0; i<4; i++){
    for(int j=i+1; j<5; j++){
      int64_t Pro=1;
      for(int k=0; k<5; k++){
        if(k!=i && k!=j){
          Pro*=M.at(k);
        }
      }
      Ans+=Pro;
    }
  }
  cout << Ans << endl;
}