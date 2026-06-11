#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 100000000000000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

int main(){
  /*ll N,M;cin >> N >> M;
  vector<tuple<ll,ll,ll>> edges;
  for(int i = 0;i < M;i++){
    int a,b,c;cin >> a >> b >> c;
    a--;b--;
    c = -c;
    edges.emplace_back(a,b,c);
  }
  bool upd = true;
  vector<ll> d(N,INF);
  d[0] = 0;
  ll step = 0;
  vector<bool> NEG(N,0);
  while(upd){
    upd = false;
    for(int i = 0;i < M;i++){
      ll a,b,c;
      tie(a,b,c) = edges[i];
      if(NEG[a]){
        NEG[b] = 1;
      }
      ll newD = d[a] + c;
      if(d[b] > newD){
        upd = true;
        d[b] = newD;
        NEG[b] = 1;
      }
    }
    step++;
    if(step > N * 2){
      cout << "inf" << endl;
      return 0;
    }
  }
  cout << -d[N-1] << endl;*/
  ll N;cin >> N;
  vector<ll> A(N);
  vector<ll> B(1,1);
  for(int i = 0;i < N;i++)cin >> A[i];
  for(int i = 0;i < N-1;i++){
    if(A[i] == A[i+1])B.back()++;
    else B.push_back(1);
  }
  ll ans = 0;
  for(int i = 0;i < B.size();i++){
    ans += B[i] / 2;
  }
  cout << ans << endl;
}