#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 1e19;
#define all(v) v.begin(), v.end()

int main(){
  ll N,K,m=INF;
  cin >> N >> K;
  vector<P> A(N);
  vector<ll> X(N),Y(N);
  rep(i,N){
    cin >> X.at(i) >> Y.at(i);
    A.at(i)=P(X.at(i),Y.at(i));
  }
  sort(all(X));
  sort(all(Y));
  rep(a,N){
    for(ll b=a+1;b<N;b++){
      rep(c,N){
        for(ll d=c+1;d<N;d++){
          ll k=0;
          rep(i,N){
            if(A.at(i).first>=X.at(a)&&A.at(i).first<=X.at(b)&&A.at(i).second>=Y.at(c)&&A.at(i).second<=Y.at(d)){
              k++;
            }
          }
          if(k>=K){
            m=min(m,(X.at(b)-X.at(a))*(Y.at(d)-Y.at(c)));
          }
        }
      }
    }
  }
  cout << m << endl;
      
}
    