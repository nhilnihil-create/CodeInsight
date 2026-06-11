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
  
void solve() {
	int n, m;
	cin >> n >> m;
	
	map<int, int> u;
	for(int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for(int j = 0; j < k; j++) {
			int a;
			cin >> a;
			u[a]++;
		}
	}
	
	int ans = 0;
	for(ii i : u) {
		if(i.ss == n) ans++;
	}
	
	cout << ans << endl;
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