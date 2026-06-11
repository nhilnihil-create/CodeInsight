  #include <bits/stdc++.h>
  using namespace std;

  const int MOD = 1000000007;

  //long long
  using ll = long long;

  //出力系
  #define print(x) cout << x << endl
  #define yes cout << "Yes" << endl
  #define YES cout << "YES" << endl
  #define no cout << "No" << endl
  #define NO cout << "NO" << endl
  
  // begin() end()
  #define all(x) (x).begin(),(x).end()

  //for
  #define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

  //最大公約数（ll）
  ll gcd(ll x, ll y) { return y ? gcd(y,x%y) : x;}

  //素因数分解
  vector<pair<ll, int>>factorize(ll n){
    vector<pair<ll, int>> res;
    for(ll i = 2; i * i <= n; ++i){
      if(n % i) continue;
      res.emplace_back(i, 0);
      while(n % i == 0){
        n /= i;
        res.back().second++;
      }
    }
  if(n != 1) res.emplace_back(n, 1);
  return res;
  }






int main() {
	string S;
	cin >> S;
	if (S.find("KIH") == string::npos) {
		cout << "NO";
		return 0;
	}
	int count = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'A') {
			S.erase(S.begin() + i);
			count++;
			if (count >= 2) {
				cout << "NO";
				return 0;
			}
          	i--;
		}
		else {
			count = 0;
		}
	}
	if (S == "KIHBR")
		cout << "YES";
	else
		cout << "NO";
	return 0;
}

