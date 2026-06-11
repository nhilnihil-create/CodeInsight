#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i,n) for(int i=0; i<n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL

ll MOD = 1000000007;
ll n;

ll Pow(ll m){ //m^nを返す
  ll ret = 1;
  rep(i,n){
    ret *= m;
    ret %= MOD;
  }
  ret %= MOD;
  //cout << "m=" << m << ",ret = " << ret << endl;
  return ret;
}

int SumDig(int i){
  string s = to_string(i);
  int sum = 0;
  rep(j,s.size()){
    sum += s[j] - '0';
  }
  return sum;
}

int main(){
  int n,a,b;
  cin>>n>>a>>b;
  int sum = 0;
  for (int i=1; i<=n; i++){
    int dig = 0;
    dig += SumDig(i);
    if (dig >= a && dig <= b) sum += i;
  }
  cout << sum << endl;
}