#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

bool compare(pii x, pii y){
  return x.second < y.second;
}

int main(){
  cout << setprecision(10);
  int N,M;
  cin >> N >> M;
  vector<pii> v(M);
  for(int i = 0; i < M; i++){
    int tmp1,tmp2;
    cin >> tmp1 >> tmp2;
    v.at(i) = make_pair(tmp1,tmp2);
  }

  sort(v.begin(), v.end(), compare);

  int ans = 1;
  int now = v[0].second;

  for(int i = 1; i < M; i++){
    if(v[i].first < now){
      continue;
    } else { 
      ans += 1;
      now = v[i].second;
    }
  }
  cout << ans << endl;



}
