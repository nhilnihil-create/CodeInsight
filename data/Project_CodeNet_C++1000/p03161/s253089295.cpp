#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fr(i,a,b) for (int i=a ; i<b ; i++)
#define fre(i,a,b) for (int i=a ; i<=b ; i++)
#define mem(a, b) memset(a, (b), sizeof(a))
#define mp make_pair
#define pb push_back
#define inf (int)1e9
#define pii 3.1415926535897932384626433832795
#define mod 1000000007
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pi> vii;
typedef map<int,int> mi;
typedef set<int> si;

int a[100005];
long dp[100000005];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    int k;
    cin>>n; cin>>k;
    fre(i,1,n)
    	cin>>a[i];
    mem(dp,0);
    dp[1] = 0;
    dp[2] = abs(a[2] - a[1]);
    for(int i=3;i<=n;i++){
    	dp[i] = inf;
    	if(k<i){
    		for(int j=i-1; j>=i-k;j--){
    			dp[i] = min(dp[i],(abs(a[i] - a[j]) + dp[j]));
    		}
    	}
    	else{
    		for(int j= i-1; j>=1;j--){
    			dp[i] = min(dp[i],(abs(a[i] - a[j]) + dp[j]));
    		}
    	}
    }
    cout<<dp[n]<<endl;
}