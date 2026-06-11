#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n;
  cin >> n;
  vector < ll > v;
  for(int i = 0; i < 20; i++) v.push_back(2 * i + 1);
  string s;
  for(int i = 0; i < 40; i++) s += '0';

  for(ll i = 0; i < ((ll)1 << 20); i++){
    int tmp = n;
    string res = s;
    for(int j = 0; j < 20; j++){
      if((i >> j) & 1){
        tmp += (1 << v[j]);
        res[v[j]] = '1';
      }
    }
    if(tmp < 0) continue;
    for(int bt = 38; bt >= 0; bt -= 2){
      if(tmp >= ((ll)1 << bt)){
        tmp -= ((ll)1 << bt);
        res[bt] = '1';
      }
    }

    if(tmp == 0){
      reverse(res.begin(), res.end());
      int k = 39;
      for(int j = 0; j < 40; j++){
        if(res[j] == '1'){
          k = j;
          break;
        }
      }
      for(int j = k; j < 40; j++) cout << res[j];
      cout << '\n';
      return 0;
    }
  }
}
