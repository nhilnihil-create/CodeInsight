#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define req(i,n) for(int i = 1;i <=n;i++)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
typedef pair<int,int> P;

//最大公約数
int gcd(int a,int b){
	if (a%b == 0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}

}

//最小公倍数
int lcm(int a,int b){
	return a /gcd(a,b) * b;
}

//素数判定
bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}




int main(){
  ll n,m;
  cin >> n >> m;
  ll c[n+1],b[n+1];
  vector<pair <ll,ll>> a;
  rep (i,n){
    cin >> c[i] >> b[i];
    a.push_back({c[i],b[i]});
  }
  sort(a.begin(),a.end());
  ll ans=0,cnt=0;
  for (auto v : a){
    while (v.second>0){
      if (cnt==m) break;
      ans += v.first;
      cnt++;
      //cout << ans << endl;
      v.second--;
    }
  }
  //cout << cnt << endl;
  cout << ans << endl;

  
}