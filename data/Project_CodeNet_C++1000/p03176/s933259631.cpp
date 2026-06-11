#include<bits/stdc++.h>
#define ull unsigned long long int 
#define pb push_back
#define F first
#define S second
#define ll long long 
#define ld long double 

#define int long long int

const int mod = 1e9+7;
const ll inf = 1e18; 
 
int power(int x,int y){int res=1;x=x%mod;while(y>0){if(y&1)res=(res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
int ncr(int n, int r){ int C[r+1]; memset(C, 0, sizeof(C)); C[0] = 1; for(int i = 1; i <= n; i++) {int t=i;if(r<t)t=r; for (int j = t; j > 0; j--) C[j] = C[j] + C[j-1]; }return C[r];} 
int gcd(int a,int b){if (a==0)return b;return gcd(b%a,a);}
int lcm(int a,int b){return (a/gcd(a,b)*b);}

int min(int a , int b){return a < b ? a : b;}
int max(int a , int b){return a > b ? a : b;}

using namespace std;

const int MAX = 200005;

int dp[MAX] , tree[4*MAX] = {} , h[MAX] , a[MAX];

int update(int pos , int value , int l , int r , int index){
	if(l == r)
		return tree[index] = max(tree[index] , value);
		
	if(l > pos || r < pos){
		return 0; // minimum
	}
	
	int mid = (l+r)/2;
	int x = update(pos , value , l , mid , 2*index);
	int y = update(pos , value , mid+1 , r , 2*index + 1);
	
	return tree[index] = max(tree[index] , max(x , y));
}

int get(int l , int r , int left , int right , int index){
	if(l > right || r < left){
		return 0;
	}
	
	if(l  >= left && r <= right)
		return tree[index];
		
	int mid = (l+r)/2;
	
	int x = get(l , mid , left , right , 2*index);
	int y = get(mid+1 , r , left , right , 2*index + 1);
	
	return max(x , y);
}


signed main(){

	 ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	for(int i = 1 ; i <= n ; i++){
		cin >> h[i];
	}
	
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	
	int ans = 0;
	for(int flower = 1 ; flower <= n ; flower++){
		int max_beauty = get(1 , n , 1 , h[flower]-1 , 1); // from 1 to h[flower]-1 , in between 1 and n
		dp[h[flower]] = max_beauty + a[flower];
		//cout << max_beauty << endl;
		ans = max(ans , dp[h[flower]]);
		int temp = update(h[flower] , dp[h[flower]] , 1 , n , 1);
	}
	
	cout << ans;
	
}








