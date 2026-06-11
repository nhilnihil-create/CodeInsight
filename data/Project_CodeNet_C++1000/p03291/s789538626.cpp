#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define tll tuple<ll, ll, ll>
#define all(c) c.begin(),c.end()
 
const ll inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;

//vector<ll> g[202020];
//fill(score, score+202020, 0);
vector<ll> v[505];

//i've not understood.
int main(){
  string S;
  cin >> S;
  int N = S.size(), MOD = 1000000007;

  ll dp[100010][4] = {};
  for(int i = N; i >= 0; --i){
    for(int j = 3; j >= 0; --j){
      if(i == N){
        dp[i][j] = (j == 3 ? 1 : 0);
      }else{
        dp[i][j] = dp[i+1][j] * (S[i] == '?' ? 3LL : 1LL);
        if(j < 3 && (S[i] == '?' || S[i] == "ABC"[j])){
          dp[i][j] += dp[i+1][j+1];
        }
        dp[i][j] %= MOD;
      }
    }
  }
  /*
  for(int i = 0; i <= N; i++){
    for(int j = 0; j <= 3; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  */
  
  cout << dp[0][0] << endl;
}