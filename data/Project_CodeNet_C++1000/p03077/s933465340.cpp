#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define All(a) a.begin(),a.end()
#define INF 1000000007
const int MOD = 1000000007;
//accumulate(vec.begin(), vec.end(), 0)
//std::sort(v.begin(), v.end(), std::greater<Type>());


ll N,A,B,C,D,E;

int main(){
  cin >> N >> A  >> B >> C >> D >> E;
  ll mi = min(min(min(min(A,B),C),D),E);
  if(mi>=N) cout<< 5 <<endl;
  else cout<< (N+mi-1)/mi+4 <<endl;

}
