#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int N; cin >> N;
  vector<pair<int, int> > ret;
  vector<int> p(N+1);
  if(N % 2 == 1){
  	for(int i = 1; i < N; i++){
      p[i] = N - i;
    }
    p[N] == -1;
  }else{
    for(int i = 1; i <= N; i++){
      p[i] = N - i + 1;
    }
  }
  
  for(int i = 1; i <= N; i++){
    for(int j = i + 1; j <= N; j++){
      if(j != p[i]) ret.push_back(make_pair(i, j));
    }
  }
  
  cout << ret.size() << endl;
  for(auto e: ret){
    cout << e.first << ' ' << e.second << endl;
  }
}