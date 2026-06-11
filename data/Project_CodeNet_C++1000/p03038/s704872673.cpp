#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N,M; cin >> N >> M;

  map<ll, int> m;
  for(int i = 0; i < N; i++){
    ll tmp; cin >> tmp;
    m[tmp]++;
  }

  vector<pli> v;
  for(int i = 0; i < M; i++){
    int B;
    ll C;
    cin >> B >> C;
    v.push_back(make_pair(C,B));
  }

  for(auto x: m){
    v.push_back(make_pair(x.first, x.second));
  }

  sort(v.rbegin(), v.rend());

  int num = 0;
  ll sum = 0;
  for(int i = 0; i < v.size(); i++){
    // cerr << v[i].first << " " << v[i].second << endl;
    if(num + v[i].second < N){
      num += v[i].second;
      sum += v[i].first * v[i].second;
    } else {
      sum += v[i].first * (N - num);
      break;
    }
  }
  cout << sum << endl;

}
