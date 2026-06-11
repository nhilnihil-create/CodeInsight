#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N;
  map<string,int> B;
  vector<string> C(N);
  for(int i=0;i<N;i++){
    string S;
    cin >> S;
    C.at(i)=S;
    if(B.count(S)){
      B.at(S)++;
    }
    else{
      B[S]=1;
    }
  }
  cin >> M;
  map<string,int> R;
  for(int i=0;i<M;i++){
    string S;
    cin >> S;
    if(R.count(S)){
      R.at(S)++;
    }
    else{
      R[S]=1;
    }
  }
  int max_ans=0;
  for(int i=0;i<N;i++){
    int ans;
    if(R.count(C.at(i))){
      ans=B.at(C.at(i))-R.at(C.at(i));
    }
    else{
      ans=B.at(C.at(i));
    }
    max_ans=max(max_ans,ans);
  }
  cout << max_ans << endl;
}  