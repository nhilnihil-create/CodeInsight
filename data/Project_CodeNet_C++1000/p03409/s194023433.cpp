#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<pair<int,int>> red(n);
  vector<pair<int,int>> blue(n);
  int a,b;
  for(int i=0;i<n;i++){
    cin >> a >> b;
    red.at(i) = make_pair(-b,a);
  }
  sort(red.begin(),red.end());
  for(int i=0;i<n;i++){
    cin >> a >> b;
    blue.at(i) = make_pair(a,b);
  }
  sort(blue.begin(),blue.end());
  int ans = 0;
  vector<bool> use_red(n,true);
  vector<bool> use_blue(n,true);
  for(int i=0; i<n; i++){
    if(use_blue.at(i)){
      for(int j=0; j<n; j++){
        if(use_red.at(j)){
          if((-red.at(j).first)<blue.at(i).second&&red.at(j).second<blue.at(i).first){
            //cout << red.at(j).first << ' ' << blue.at(i).second << endl;
            use_blue.at(i) = false;
            use_red.at(j) = false;
            ans++;
            break;
          }
        }
      }
    }
  }
  cout << ans << endl;
}