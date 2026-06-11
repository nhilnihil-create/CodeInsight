#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  ll N;
  cin >> N;
  map<ll,ll> B;
  map<ll,ll> C;
  vector<ll> A(N);
  REP(i, N){
    cin >> A[i];
    if(i%2==0){
      B[A[i]]++;
    }else{
      C[A[i]]++;
    }
  }

  vector<P> D;
  vector<P> E;
  for(auto x:B){
    D.push_back(make_pair(x.second,x.first));
  }
  for(auto x:C){
    E.push_back(make_pair(x.second,x.first));
  }
  sort(ALL(D));
  reverse(ALL(D));
  sort(ALL(E));
  reverse(ALL(E));

  if(D.at(0).second==E.at(0).second){
    if(D.at(0).first<E.at(0).first){
      cout << (N/2-E.at(0).first)+(N/2-D.at(1).first) << endl;
    }else if(D.at(0).first>E.at(0).first){
      cout << (N/2-D.at(0).first)+(N/2-E.at(1).first) << endl;
    }else{
      if(D.at(0).first==N/2){
        cout << N/2 << endl;
      }else{
        cout << min((N/2-D.at(0).first)+(N/2-E.at(1).first),(N/2-D.at(1).first)+(N/2-E.at(0).first)) << endl;
      }
    }
  }else{
    cout << (N/2-D.at(0).first)+(N/2-E.at(0).first) << endl;
  }
}
