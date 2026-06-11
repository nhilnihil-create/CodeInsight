#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;

template <class T>
using lim = numeric_limits<T>;

bool can[10];
int cost[10] = {0,2,5,5,4,5,6,3,7,6};
char num[10] = {'0','1','2','3','4','5','6','7','8','9'};

// stores a big number
// supports comparison and cout
struct bigInt{
	string s;
	
	bigInt(){s="0";}
	bigInt(string a){s=a;}
	
	bigInt append(char a){
		return bigInt(s+a);
	}
	
	bool operator<(const bigInt &other)const{
		int n = s.length();
		int m = other.s.length();
		if (n != m) return n < m;
		for (int i = 0; i < n; i++){
			if (s[i] == other.s[i]) continue;
			return (int)s[i]-'0' < (int)other.s[i]-'0';
		}
		return true;
	}
	
	friend ostream& operator<<(ostream &os, const bigInt a);
};

ostream& operator<<(ostream& os, const bigInt a){
	os << a.s;
	return os;
}

int main() {
	ios_base::sync_with_stdio(false) ;
	cin.tie(0);
	
	memset(can, 0, sizeof can);
	
	int n, m;
	cin >> n >> m;
	
	bigInt dp[n+1];
	dp[0] = bigInt("");
	for (int i = 0; i < m; i++){
		int a; cin >> a;
		can[a] = true;
	}
	
	// adding all available matches and getting the max
	// dp[i] is maximum val at i
	for (int i = 0; i < n; i++){
		for (int j = 1; j < 10; j++){
			if (!can[j] || dp[i].s=="0" || i + cost[j] > n) continue;
			dp[i+cost[j]] = max(dp[i+cost[j]], dp[i].append(num[j]));
		}
	}
	
	cout << dp[n] << endl;
}

