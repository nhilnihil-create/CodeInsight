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


int N = 100010;
int prime[100010];//i番目の素数
bool is_prime[100011]; //is_prime[i] がTrueならiは素数

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
  return p;//pは素数の数
}

int main(){
  sieve(N);
  int ans[N];
  ans[0] = 0;
  rep (i, N-1){
    if ((i + 1) % 2 == 1 && is_prime[i+1] && is_prime[(i + 2)/2]){
        ans[i+1] = ans[i] + 1;
    }
    else{
      ans[i + 1] = ans[i];
    }
  }
  int Q;
  int l, r;
  cin >> Q; 
  rep(i, Q){
    cin >> l >> r;
    cout << ans[r]-ans[l-1] <<endl;
  }
}
