#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1) 
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()  
#define int long long
#define ld long double
#define fast  ios_base::sync_with_stdio(false);  cin.tie(NULL);
const int MOD = 1e9+7;
const int inf = 1e9+9;
const int MAX = 1e5+5;
typedef vector<int> vi;
typedef pair<int,int> pii; 

int max(int a, int b){return a>b? a:b;}
int min(int a, int b){return a<b? a:b;}
int power(int a, int b){
    if(b==0)
        return 1;
    int x = power(a, b/2);
    x = (x*x)%MOD;
    if(b&1){
        x = (x*a)%MOD;
    }
    return x;
}
int gcd(int a, int b){
	if(a>b) swap(a,b);
	if(b==0) return a;
	return gcd(b, a%b);
}
int countsetbits(int n){
    int cnt=0;
    while(n){
        cnt++;
        n = n&(n-1);
    }
    return cnt;
}
 
int dp[(1<<21)+1];
void solve(){
	int n;
    cin>>n;
    int like[n+1][n+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>like[i][j];
        }
    }  
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    for(int mask=0;mask<=(1<<n)-1;mask++){  
        int y = countsetbits(mask);
        for(int i=0;i<n;i++){
            if((mask&(1<<i)) == 0 && like[y][i]){
                dp[mask|(1<<i)] += dp[mask];
                dp[mask|(1<<i)]%=MOD;
            }
        }
    }
    cout << dp[(1<<n)-1];
}

int32_t main(){ 
	fast
	int t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}