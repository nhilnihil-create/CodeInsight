#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {

  int N;
  cin >> N;

  map<pair<int,int>,int> mp;
  vector<pair<int,int>> vec(0);

  if(N % 2 == 0) {
    for(int i = 1;i <= N;i++) {
      for(int j = 1;j <= N;j++) {
        if(i == j) continue;
        if(i+j == N+1) continue;
        if(!mp[make_pair(i,j)]) {
          mp[make_pair(j,i)]++;
          vec.emplace_back(i,j);
        }
      }
    }
  }else {
    for(int i = 1;i < N;i++) {
      for(int j = 1;j < N;j++) {
        if(i == j) continue;
        if(i+j == N) continue;
        if(!mp[make_pair(i,j)]) {
          mp[make_pair(j,i)]++;
          vec.emplace_back(i,j);
        }
      }
      vec.emplace_back(i,N);
    }
  }

  cout << vec.size() << endl;
  for(auto p : vec) {
    cout << p.first << " " << p.second << endl;
  }
}
