#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pll = pair<long long, long long>;
const int INF = 1<<29;

int unko(int n, vector<int> like2017){
  int s = like2017.size();
  for(int i=0;i<s;i++){
    if(n < like2017.at(i))return i;
  }
  return s;
}

int main(){
  int q;
  cin >> q;
  vector<pii> num(q);
  for(int i=0;i<q;i++){
    cin >> num.at(i).first >> num.at(i).second;
  }
  vector<int> sosu(100001,1);
  sosu.at(0) = 0;
  sosu.at(1) = 0;
  for(int i=2;i<=317;i++){
    if(sosu.at(i) == 1){
      for(int j=2;i*j<=100000;j++){
        sosu.at(i*j) = 0;
      }
    }
  }
  vector<int> like2017;
  for(int i=3;i<100001;i++){
    if(sosu.at(i) && sosu.at((i+1)/2)){
      like2017.push_back(i);
    }
  }
  int s = like2017.size();
  for(int i=0;i<q;i++){
    int ans = unko(num.at(i).second,like2017) - unko(num.at(i).first-1,like2017);
    cout << ans << endl;
  }
}