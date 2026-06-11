#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1000000007;

void addzero(int x){
  int cnt = 0,y=x;
  while(y>0){
    cnt ++;
    y /= 10;
  }
  for(int i=0;i<6-cnt;i++){
    cout << '0';
  }
  cout << x;
}

int main(){
  int N,M;cin >> N >> M;
  vector<int> P(M);
  vector<int> Y(M);
  vector<vector<pair<int,int>>> V(N);
  for(int i=0;i<M;i++){
    cin >> P[i] >> Y[i];
    pair<int,int> U = make_pair(Y[i],i);
    V[P[i]-1].push_back(U);
  }
  for(int i=0;i<N;i++){
    sort(V[i].begin(),V[i].end());
    for(int j=0;j<V[i].size();j++){
      Y[V[i][j].second] = j + 1;
    }
  }
  for(int i=0;i<M;i++){
    addzero(P[i]);
    addzero(Y[i]);
    cout << endl;
  }
}