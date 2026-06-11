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
  ll sumA=0;
  ll sumB=0;
  vector<ll> A(N);
  REP(i, N){
    cin >> A[i];
    sumA+=A[i];
  }
  vector<ll> B(N);
  REP(i, N){
    cin >> B[i];
    sumB+=B[i];
  }  

  if(sumB<sumA){
    cout << "No" << endl;
  }else{
    ll xA = sumB-sumA;
    ll xB = sumB-sumA;
    REP(i,N){
      if(A[i]>B[i]){
        xB-=A[i]-B[i];
      }else if(A[i]<B[i]){
        if((B[i]-A[i])%2==0){
          xA-=(B[i]-A[i])/2;
        }else{
          xA-=(B[i]-A[i])/2+1;
        }
        xB-=(B[i]-A[i])%2;
      }
    }
    if(xA*2==xB&&xA>=0&&xB>=0){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}