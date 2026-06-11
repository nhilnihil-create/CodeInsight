#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<vector<int>> F(N, vector<int>(10));
  for(int i=0; i<N; i++){
    for(int j=0; j<10; j++){
      cin >> F.at(i).at(j);
    }
  }
  vector<vector<int>> P(N, vector<int>(11));
  for(int i=0; i<N; i++){
    for(int j=0; j<=10; j++){
      cin >> P.at(i).at(j);
    }
  }
  int64_t Ans=-1000000000000;
  for(int i=1; i<1024; i++){
    int64_t subAns=0;
    int j=i;
    vector<int> G(10, 0);
    for(int k=0; k<10; k++){
      if(j%2==1){
        G.at(k)=1;
      }
      j/=2;
    }
    for(int k=0; k<N; k++){
      int c=0;
      for(int u=0; u<10; u++){
        c+=F.at(k).at(u)*G.at(u);
      }
      subAns+=P.at(k).at(c);
    }
    Ans=max(Ans, subAns);
  }
  cout << Ans << endl;
}