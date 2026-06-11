#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
using namespace std;
using ll = long long;
using ld = long double;

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  cin >> N;
  vector<vector<ll>> a(N,vector<ll>(N));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> a.at(i).at(j);
    }
  }

  vector<ll> group(1<<N);
  for(int bit=0;bit<(1<<N);bit++){
    bitset<16> S(bit);
    ll tmp=0;
    for(int i=0;i<N;i++){
      if(!S.test(i))  continue;
      for(int j=i;j<N;j++){
        if(!S.test(j))  continue;
        tmp+=a.at(i).at(j);
      }
    }
    group.at(bit)=tmp;
  }

  vector<ll> dp((1<<N),1e-15);
  dp.at(0)=0;
  for(int bit=0;bit<(1<<N);bit++){
    for(int g=bit;g>0;g=(g-1)&bit){
      dp.at(bit)=max(dp.at(bit),dp.at(bit-g)+group.at(g));
    }
  }
  cout << dp.at((1<<N)-1) << endl;

  return 0;
}