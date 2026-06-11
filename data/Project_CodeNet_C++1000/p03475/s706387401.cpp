#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589;

int n;
int c[500], s[500], f[500];
int ans = 0;

//時刻tに駅iを出発して、最初に駅Nに着く時刻
int func(int t, int i){
  if(i == n-1) return t;
  //次の電車の発車時刻
  int k = 0;
  while(t > s[i] + k * f[i]) k++;
  return func(s[i] + k*f[i] + c[i], i+1);
}
  

int main(){
  cin >> n;
  rep(i, n-1) cin >> c[i] >> s[i] >> f[i];
  rep(i, n) cout << func(s[i], i) <<endl;
}