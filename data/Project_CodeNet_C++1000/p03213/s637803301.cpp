#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

bool isprime(int n){
  for(int i = 2;i*i <= n;i++)if(!(n%i))return false;
  return true;
}

int main(){

  int n;
  cin >> n;
  vector<int> v(100,0);
  for(int i = 2;i <= n;i++){
    if(!isprime(i))continue;
    int cnt = 0;
    int l = i;
    while(l <= n){
      cnt += n/l;
      l *= i;
    }
    if(cnt < 2)v[0]++;
    else if(cnt < 4)v[3]++;
    else if(cnt < 14)v[5]++;
    else if(cnt < 24)v[15]++;
    else if(cnt < 74)v[25]++;
    else v[75]++;
  }
  ll res = 0;
  res += v[75];
  res += (v[3]+v[5]+v[15])*(v[25]+v[75])+(v[25]+v[75])*(v[25]+v[75]-1);
  res += v[5]*(v[15]+v[25]+v[75])+(v[15]+v[25]+v[75])*(v[15]+v[25]+v[75]-1);
  res += v[3]*(v[5]+v[15]+v[25]+v[75])*(v[5]+v[15]+v[25]+v[75]-1)/2+(v[5]+v[15]+v[25]+v[75])*(v[5]+v[15]+v[25]+v[75]-1)*(v[5]+v[15]+v[25]+v[75]-2)/2;
  cout << res << endl;

  



  return 0;
}