#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,T;
  cin >> N >>T;
  vector<pair<int,int>> p(N);
  for(int i = 0; i < N; i++){
    int c,t;
    cin >> c >> t;
    p.at(i) = make_pair(c,t);
  }
  int cost = 1001;
  int ans = -1;
  for(int i = 0; i < N; i++){
    if (p.at(i).second <= T){
      if(p.at(i).first < cost){
        cost = p.at(i).first;
        ans = i;
      }
    }
  }
  if(ans == -1)cout << "TLE"<<endl;
  else cout << cost << endl;
}