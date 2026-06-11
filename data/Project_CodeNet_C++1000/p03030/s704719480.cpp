#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(int)(n);i++)

int N;
using psii = pair<pair<string, int>, int>;

int main() {
  cin>>N;
  vector<psii> vec(N);
  rep(i, N){
    cin>>vec[i].first.first>>vec[i].first.second;
    vec[i].second=i+1;
    vec[i].first.second*=-1;
  }
  sort(vec.begin(), vec.end());

  for(auto v: vec){
    cout<<v.second<<endl;
  }
}