#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
 
//recollect
//simplify
//divide into cases (i.e. i = 1, 2, N, a prime number, etc...)
  
string maxstr(string a, string b) {
	if(a.size() > b.size()) return a;
	else if(b.size() > a.size()) return b;
	if(a > b) return a;
	else return b;
}
  
int cost[] = {2, 5, 5, 4, 5, 6, 3, 7, 6};  
  
void solve() {
	int n, m;
	cin >> n >> m;
	
	vi a(m);
	for(int i = 0; i < m; i++) cin >> a[i], a[i]--;
	
	vector<string> dp(n + 1, ".");
	dp[0] = "";
	for(int i = 0; i < n; i++) {
		if(dp[i] == ".") continue;
		for(int j = 0; j < m; j++) {
			if(i + cost[a[j]] <= n) dp[i + cost[a[j]]] = maxstr(dp[i] + (char)(a[j] + '0' + 1), dp[i + cost[a[j]]]);
		}
	} 
	
	cout << dp[n] << endl;
}
 
int main(){
#define MULTITEST 0
#if MULTITEST   
 
    CASET {
        solve();
    }
    
#else
 
    solve();
    
#endif
 
    return 0;
}