#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;

ll gcd(ll x,ll y){
  return y==0? x:gcd(y,x%y);
}
bool used[30000];
int main() {
  int N;
  cin >> N;
  set<ll> S;
  for(ll i=2;i<=30000;i+=2){
    S.insert(i);
  }
  for(ll i=3;i<=30000;i+=3){
    S.insert(i);
  }
  ll sum=0;
  for(auto a:S){
    cout << a << " ";
    used[a]=true;
    sum+=a;
    N--;
    if(N==1) break;
  }
  for(int i=2;i<=30000;i++){
    if(!used[i]&&gcd(sum,i)!=1&&(sum+i)%2==0&&(sum+i)%3==0){
      cout << i << endl;
      break;
    }
  }
  return 0;
}
