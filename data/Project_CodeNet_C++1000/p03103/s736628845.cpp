#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> P(N);
  int A, B;
  for(int i=0; i<N; i++){
    cin >> A >> B;
    P.at(i)=make_pair(A, B);
  }
  sort(P.begin(), P.end());
  int Now=0;
  int64_t Ans=0;
  for(int i=0; i<M; i++){
    if(P.at(Now).second>0){
      P.at(Now).second--;
      Ans+=P.at(Now).first;
    }
    else{
      Now++;
      i--;
    }
  }
  cout << Ans << endl;
}