#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N;
  cin >> N;
  vector<vector<int64_t>> G(N);
  for(int i=0; i<N-1; i++){
    int64_t a, b;
    cin >> a >> b;
    G.at(a-1).push_back(b-1);
    G.at(b-1).push_back(a-1);
  }
  
  vector<int64_t> C(N);
  for(int i=0; i<N; i++){
    cin >> C.at(i);
  }
  sort(C.rbegin(),C.rend());
  
  vector<int64_t> ans(N);
  vector<bool> seen(N,false);
  queue<int> Q;
  int cnt = 0;
  Q.push(0);
  seen.at(0) = true;
  ans.at(0) = C.at(cnt);
  while(Q.size()){
    int x = Q.front();
    Q.pop();
    for(int i=0; i<G.at(x).size(); i++){
      if(!seen.at(G.at(x).at(i))){
        cnt++;
        ans.at(G.at(x).at(i)) = C.at(cnt);
        seen.at(G.at(x).at(i)) = true;
        Q.push(G.at(x).at(i));
      }
    }
  }
  int M = 0;
  for(int i=1; i<N; i++){
    M += C.at(i);
  }
  cout << M << endl;
  for(int i=0; i<N; i++){
    cout << ans.at(i) << endl;
  }
}