#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  int N;
  cin >> N;

  vector<pair<int,int>> r(N),b(N);
  for(int i = 0;i < N;i++) cin >> r.at(i).first >> r.at(i).second;

  for(int i = 0;i < N;i++) cin >> b.at(i).first >> b.at(i).second;

  sort(b.begin(),b.end());
  int ans = 0;
  for(int i = 0;i < N;i++) {
    int x = b.at(i).first,y = b.at(i).second;
    int MY = -1,idx = -1;
    for(int j = 0;j < N;j++) {
      if(r.at(j).first == -1 || r.at(j).first >= x) continue;
      if(r.at(j).second > MY && r.at(j).second < y) {
        MY = r.at(j).second;
        idx = j;
      }
    }
    if(idx != -1) {
      r.at(idx).first = -1;
      ans++;
    }
  }

  cout << ans << endl;

}
