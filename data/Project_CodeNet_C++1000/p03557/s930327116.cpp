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
  vector<P> A(3*N);
  REP(i, N){
    cin >> A[i].first;
    A[i].second=-1;
  }
  FOR(i,N,2*N){
    cin >> A[i].first;
    A[i].second=-2;
  }
  FOR(i,2*N,3*N){
    cin >> A[i].first;
    A[i].second=-3;
  }
  sort(ALL(A));
  vector<int> vec(3*N);
  REP(i,3*N){
    vec.at(i)=-1*A.at(i).second;
  }

  ll cnt1=0;
  ll cnt12=0;
  ll cnt123=0;
  vector<ll> vec1(3*N,0);
  vector<ll> vec12(3*N,0);
  vector<ll> vec123(3*N,0);
  REP(i,3*N){
    if(vec.at(i)==1){
      cnt1++;
      vec1.at(i)=cnt1;
      if(i!=0){
        vec12.at(i)=vec12.at(i-1);
        vec123.at(i)=vec123.at(i-1);
      }
    }else if(vec.at(i)==2){
      if(i!=0){
        cnt12+=vec1.at(i-1);
        vec12.at(i)=cnt12;
        vec1.at(i)=vec1.at(i-1);
        vec123.at(i)=vec123.at(i-1);
      }
    }else{
      if(i!=0){
        cnt123+=vec12.at(i-1);
        vec123.at(i)=cnt123;
        vec1.at(i)=vec1.at(i-1);
        vec12.at(i)=vec12.at(i-1);
      }
    }
  }
  cout << vec123.at(3*N-1) << endl;
}