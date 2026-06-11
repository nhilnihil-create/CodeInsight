#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<int> W(N+1);
  W.at(0)=0;
  for(int i=0;i<N;i++){
    W.at(i+1)=W.at(i);
    if(S.at(i)=='W'){
      W.at(i+1)++;
    }
  }
  int min_ans=1000000000;
  for(int i=1;i<N+1;i++){
    int ans=W.at(i-1)+W.at(i)-W.at(N)+N-i;
    min_ans=min(min_ans,ans);
  }
  cout << min_ans << endl;
}