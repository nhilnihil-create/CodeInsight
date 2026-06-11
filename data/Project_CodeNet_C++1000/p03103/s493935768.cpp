#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n,m; cin >> n >> m;
  long ans = 0L;
  vector<pair<long, long>> drink;
  for(int i = 0; i < n; i++){
    long a;int b;
    cin >> a >> b;
    drink.push_back(make_pair(a,b));
  }
  sort(drink.begin(), drink.end());
  for(int i = 0; i < n; i++){
    if(m <= drink.at(i).second){
      ans += drink.at(i).first * m;
      break;
    }
    else{
      ans += drink.at(i).first * drink.at(i).second;
      m -= drink.at(i).second;
    }
  }
  cout << ans;
}