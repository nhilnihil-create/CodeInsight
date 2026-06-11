#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, m, n) for(int i = m; i <= n; i++)
#define per(i, m, n) for(int i = m; i >= n; i--)
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 
#define vi vector<int> 
#define vll vector<ll> 
#define sz(v) (int) v.size()
const int INF = 0x3f3f3f3f;

const int maxn = (1 << 18) + 5;

struct Num {
	int maxx, sec_maxx; 
} a[maxn]; 

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    int N;
    cin >> N;
    for (int i = 0; i < (1 << N); i++) 
    	cin >> a[i].maxx; 
    for (int j = 0; j < N; j++) {
    	for (int i = 0; i < (1 << N); i++) {
    		if ((i >> j) & 1) {
    			int x = i ^ (1 << j); 
    			Num ans; 
    			ans.maxx = max(a[i].maxx, a[x].maxx); 
    			if (a[i].maxx > a[x].maxx) ans.sec_maxx = max(a[i].sec_maxx, a[x].maxx); 
    			else ans.sec_maxx = max(a[i].maxx, a[x]. sec_maxx); 
  				a[i] = ans; 
    		}
    	}
    }
    int ans = 0; 
    for (int i = 1; i < (1 << N); i++) {
    	ans = max(ans, a[i].maxx + a[i].sec_maxx); 
    	cout << ans << endl; 
    }
    return 0; 
}