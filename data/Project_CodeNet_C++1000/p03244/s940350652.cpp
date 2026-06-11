#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;

  map<int,int> odd,even;
  odd[0] = 0;
  even[0] = 0;

  for(int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    if(i %2 == 0){
      if(odd.count(tmp) == 0){
        odd[tmp] = 1;
      } else {
        odd[tmp] += 1;
      }
    } else { 
      if(even.count(tmp) == 0){
        even[tmp] = 1;
      } else {
        even[tmp] += 1;
      }
    }
  }
  // odd と evenの頻度1位と2位を取り出す
  vector<pair<int,int>> v_odd;
  for(auto x: odd){
    v_odd.push_back(make_pair(x.second, x.first));
  }

  sort(v_odd.rbegin(), v_odd.rend());

  vector<pair<int,int>> v_even;
  for(auto x: even){
    v_even.push_back(make_pair(x.second, x.first));
  }
  sort(v_even.rbegin(), v_even.rend());
//  cerr << v_odd[0].first << " " << v_odd[0].second << endl;
//  cerr << v_odd[1].first << " " << v_odd[1].second << endl;
//  cerr << v_even[0].first << " " << v_even[0].second << endl;
//  cerr << v_even[1].first << " " << v_even[1].second << endl;

  int ans = 0;
  if(v_odd[0].second != v_even[0].second){
    ans += (N/2) - v_odd[0].first;
    ans += (N/2) - v_even[0].first;
  } else {
    int tmpans1 = 0;
    if(v_odd[1].first >= v_even[1].first){
      // oddを2番目にする
      ans += (N/2) - v_odd[1].first;
      ans += (N/2) - v_even[0].first;
    } else {
      ans += (N/2) - v_odd[0].first;
      ans += (N/2) - v_even[1].first;
    }
  }
  cout << ans << endl;
}
