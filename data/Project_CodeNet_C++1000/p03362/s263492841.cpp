#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

vi prime(55555);
bool is_prime[55556];

int sieve(int n){
  int p = 0;
  for (int i = 0; i <= n; i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++){
    if (is_prime[i]){
      prime[p++] = i;
      for (int j = 2*i; j <=n; j+=i) is_prime[j] = false;
    }
  }
  //return p;
}

int main(){
  sieve(55555);
  int N;
  cin >> N;
  vi ans;
  rep(i, prime.size()){
    if (prime[i] % 5 == 1){
      ans.push_back(prime[i]);
    }
    if (ans.size() == N){
      break;
    }
  }
  rep(i, N){
    cout << ans[i] << " ";
  }
}
