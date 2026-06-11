#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
typedef tuple<ll,int,int,int,int,int,int,int>T;
#define PI 3.14159265358979
const int MAX = 510000;
const int MOD = 1000000007;

void chmax(string &a, string b) {
    if (a == "-") a = b;
    else if (a.size() < b.size()) a = b;
    else if (a.size() == b.size()) {
        if (a < b) a = b;
    }
}
int main(){
  ll N,M;
  cin>>N>>M;
  vector<ll>A(M);
  int use[10]={0,2,5,5,4,5,6,3,7,6};
  rep(i,M){
  	cin>>A[i];
  } 
  string dp[11000];
  rep(i,11000){dp[i]="-";}
  dp[0]="";
  for(int i=0;i<=N;i++){
    if(dp[i]=="-"){continue;}
  	for(auto a:A){
      chmax(dp[i+use[a]], dp[i] + (char)('0' + a));
    }
  }
  cout<<dp[N];
} 
