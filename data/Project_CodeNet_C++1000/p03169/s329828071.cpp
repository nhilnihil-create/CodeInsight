#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, (b), sizeof(a))
#define fore(i,a) for(int i=0;i<a;i++)
#define fore1(i,j,a) for(int i=j;i<a;i++)
#define print(ar) for(int i=0;i<ar.size();i++)cout<<ar[i]<<" ";
#define END cout<<'\n'
const double pi=acos(-1.0);
 
typedef pair<int, int> PII;
 
typedef vector<long long> VI;
 
typedef vector<string> VS;
 
typedef vector<PII> VII;
 
typedef vector<VI> VVI;
 
typedef map<int,int> MPII;
 
typedef set<int> SETI;
 
typedef multiset<int> MSETI;
 
typedef long int li;
 
typedef unsigned long int uli;
 
typedef long long int ll;
 
typedef unsigned long long int  ull;
ll fastexp (ll a, ll b, ll n) {
  ll res = 1;
  while (b) {
      if (b & 1) res = res*a%n;
      a = a*a%n;
      b >>= 1;
  }
  return res;
}
void fast(){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
}

  
double dp[301][301][301];
 
double findAnswer(int one, int two, int three, int n) {
	if((one < 0 || two < 0 || three < 0) || (one == 0 && two == 0 && three == 0))
		return 0;
	if(dp[one][two][three] > 0)
		return dp[one][two][three];
	return dp[one][two][three] = (n + one * findAnswer(one - 1, two, three, n) + two * findAnswer(one + 1, two - 1, three, n) + three * findAnswer(one, two + 1, three - 1, n)) / (one + two + three);
}
 
void solve() {
	int n, ele, ones = 0, twos = 0, threes = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> ele;
		if(ele == 1)
			ones++;
		else if(ele == 2)
			twos++;
		else 
			threes++;
	}
	memset(dp, -1.0, sizeof(dp));
	cout << fixed << setprecision(14) << findAnswer(ones, twos, threes, n);
} 
int main()
 {  fast();
	solve();
 }
   
   