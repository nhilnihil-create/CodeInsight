#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(a) begin(a),end(a)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1e+9;
const ll mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
ll gcd(ll a, ll b){
  if (b==0) return a;
  else return gcd(b,a%b);
}
int cans(bool f){
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}


int fac(int num) {
  if(num==1) return 1;
  else return num*fac(num-1);
}


map<ll,ll> idx;
vector<bool> prime(200,true);




ll rec(map<ll,ll>::iterator p, ll mul) {
  if(p == idx.end()) {
    if(mul == 1) return 1;
    else return 0;
  }
  ll res = 0;
  for(int i=0; i < p->second+1; i++) {
    if(mul % (i+1) != 0) continue;
    res += rec(++p,mul/(i+1));
    --p;
  }
  return res;
}



int main() {
  ll N;cin >> N;
  prime[0] = false;
  prime[1] = false;
  for(int i=2; i <= 100; i++) {
    if(prime[i]) {
      for(int j=i+i; j <= 100; j+=i) {
	prime[j] = false;
      }
    }
  }
  
  for(int i=2; i<=N; i++) {
    if(prime[i]) {
      int j=1;
      ll tmp = 0;
      while(N/pow(i,j)) {
	tmp += N/pow(i,j);
	j++;
      }
      idx[i] = tmp;
    }
  }

  

  // for(auto itr : idx) cout << itr.first << " : " << itr.second << endl;
  cout << rec(idx.begin(),75) << endl;
  
  return 0;
}
