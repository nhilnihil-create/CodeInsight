#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<string,int>>vec(N);
  map<int,int>mp;
  for(int i=0; i<N; i++){
    cin >> vec[i].first >> vec[i].second;
    vec[i].second *= -1;
    mp[vec[i].second] = i+1;
  }
  sort(vec.begin(),vec.end());
  for(int i=0; i<N; i++){
    cout << mp[vec[i].second] << endl;
  }
}
