#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<ll>> v(8, vector<ll>(N));

  for(int i= 0; i < N; i++){
    ll x,y,z;
    cin >> x >> y >> z;
    v.at(0).at(i) = x + y + z;
    v.at(1).at(i) = x - y + z;
    v.at(2).at(i) = x + y - z;
    v.at(3).at(i) = x - y - z;
    v.at(4).at(i) = -x + y + z;
    v.at(5).at(i) = -x - y + z;
    v.at(6).at(i) = -x + y - z;
    v.at(7).at(i) = -x - y - z;
  }
  ll max_val = 0;
  for(int i =0 ; i < 8; i++){
    sort(v.at(i).rbegin(), v.at(i).rend());
    ll tmp = 0;
    for(int j = 0; j < M; j++){
      tmp += v.at(i).at(j);
    }
    max_val = max(tmp, max_val);
  }
  cout << max_val << endl;
}
