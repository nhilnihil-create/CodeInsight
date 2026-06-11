#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
#define PI 3.14159265359
#define MOD 1000000007
const int MAX = 510000;
ll gcd(ll a, ll b){
    if (a % b == 0)
    {  return(b);}
    else{return(gcd(b, a % b));}
}
ll lcm(ll a, ll b)
{return a * b / gcd(a, b);}

int main(){
  int N;string S;
  cin >>N>>S;
  vector<ll>turntoE(N);//i-1番目までの人が、i番目のヒトを向くとき、その人数
  vector<ll>turntoW(N);
  turntoE[0]=0;turntoW[N-1]=0;
  for(ll i=1;i<N;i++){
  	if(S[i-1]=='W'){turntoE[i]=turntoE[i-1]+1;}
    else{turntoE[i]=turntoE[i-1];}
  }
  for(ll i=N-2;i>=0;i--){
  	if(S[i+1]=='E'){turntoW[i]=turntoW[i+1]+1;}
    else{turntoW[i]=turntoW[i+1];}
  }
  ll memo=N;
  rep(i,N){
  	memo=min(memo,turntoE[i]+turntoW[i]);
  }
  cout<<memo;
}