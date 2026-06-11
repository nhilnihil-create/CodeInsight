#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(long long i=0; i<(int)n; i++)
#define rep2(i,a,n) for(long long i=(a); i<(int)(n); i++)
#define all(vec) vec.begin(),vec.end()
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using psi = pair<string, int>;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};
const int mod = 1e9+7;
int gcd(int a, int b){if(a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}

int N, M, K, H, W, L, R, X;
//string S, T;

signed main(){
  const int mn = 1e6+1;
  vector<bool> prime(mn,true);
  prime[0] = false, prime[1] = false; 
  for(int i = 2; i*i <= mn; i++){
    if(prime[i] == true){
      for(int j=i+i; j<=mn; j += i){
        prime[j]=false;
      }
    }
  }
  

  vvi l2017(mn,vi(2,0));
  int tsum = 0;
  for(int i=1; i<mn; i +=2 ){
    if(prime[i] && prime[(i+1)/2]){
      ++tsum;
      l2017[i][0] = 1;
    }
    l2017[i][1] = tsum;
  }  
  cin >> N;
  rep(i,N){
    int a, b; cin >> a >> b;
    cout << l2017[b][1]-l2017[a][1] + l2017[a][0]  << endl;
  }

  return 0;
}