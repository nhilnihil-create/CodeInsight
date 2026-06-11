#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>>data(2,vector<int>(N));
  for(int i=0;i<N;i++){
    cin >> data.at(0).at(i);
  }
  for(int i=0;i<N;i++){
    cin >> data.at(1).at(i);
  }
  int ans=0;
  for(int i=0;i<N;i++){
    int x=0;
    for(int j=0;j<=i;j++){
      x+=data.at(0).at(j);
    }
    for(int j=i;j<N;j++){
      x+=data.at(1).at(j);
    }
    ans=max(ans,x);
  }
  cout << ans << endl;
}
