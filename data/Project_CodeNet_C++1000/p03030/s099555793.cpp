#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,c;
  cin >> N;
  vector<pair<string,pair<int,int>>> in(N);
  for(int i=0;i<N;i++){
    cin >> in[i].first >> c;
    in[i].second.first = c * -1;
    in[i].second.second = i+1;
  }
  sort(in.begin(),in.end());
  for(pair x : in) cout << x.second.second << endl;
}