#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
#define ALL(a)  (a).begin(),(a).end()
const ll INF = 1e18+18;
const ll MAX = 200000;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;

ll gcd(ll a, ll b){
    if(b==0)return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a * b / gcd (a, b);
}

int main(){
  ll N, M;
  cin>>N>>M;
  vector<ll> A(M);
  vector<bool> Num(10, false);
  vector<ll> W={6,2,5,5,4,5,6,3,7,6};
  rep(i, M){
    cin>>A[i];
    Num[A[i]]=true;
  }
  vector<string> D(N+1);
  rep(i, N){
    //cout<<"turn"<<i+1<<endl;
    for(ll j=1; j<=9; j++){
      if(!(Num[j]))continue;
      if(i+1-W[j]<0)continue;
      if(i+1-W[j]==0||D[i+1-W[j]].size()!=0){

        char X=(char)((int)'0'+j);
        string S=D[i+1-W[j]]+X;
        //cout<<X<<" "<<S<<endl;
        if(S.size()<D[i+1].size())continue;
        if(S.size()>D[i+1].size()){
          D[i+1]=S;
          continue;
        }
        D[i+1]=max(D[i+1], S);
      }
    }
    //cout<<"D="<<D[i+1]<<endl;
  }
  cout<<D[N]<<endl;
}