#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MAXN = 1e5 + 5;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll m, k;
  cin >> m >> k;

  if(k > ((1 << m) - 1)){
    cout << -1 << endl;
    return 0;
  }
  if(m == 0){
    if(k == 0){
      cout << 0 << " " << 0 << endl;
    }else{
      cout << -1 << endl;
    }
    return 0;
  }
  if(m == 1){
    if(k == 0){
      cout << "0 0 1 1" << endl;
    }else{
      cout << -1 << endl;
    }
    return 0;
  }

  vector < ll > v;
  for(int i = 0;i < (1 << m); i++){
    if(i == k) continue;
    v.push_back(i);
    cout << i << " ";
  }

  cout << k << " ";
  reverse(v.begin(), v.end());
  for(auto i : v) cout << i << " ";
  cout << k << " ";
  cout << endl;
}
