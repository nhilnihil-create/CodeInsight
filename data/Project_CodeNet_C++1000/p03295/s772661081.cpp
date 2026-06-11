#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> ab(m);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    ab.at(i) = make_pair(a, b);
  }
  
  sort(ab.begin(), ab.end());
  int ans = 1;
  int cut = ab.at(0).second;
  for(int i = 0; i < m; i++){
    int ka = ab.at(i).first, kb = ab.at(i).second;
    if(ka >= cut){
      cut = kb;
      ans++;
    }
    else cut = min(cut, kb);
  }
  
  cout << ans << endl;
}