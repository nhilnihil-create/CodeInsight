#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define finput ifstream cin;cin.open("in.txt")
#define foutput ofstream cout;cout.open("out.txt")  
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mod 1000000007

ll gcd(ll x, ll y){ 
	if(x<y) 
		swap(x,y); 
	if(x%y==0)
		return y;
	return gcd(y, x%y);
}

ll pwm(ll a, ll n){
	ll ans = 1;
	while(n>0){
		if(n%2==1){
			ans = (ans * a)%mod;
		}
		a = (a*a)%mod;
		n /= 2;
	}
	return ans%mod;
}

const int pwn = 100010;
ll pw[pwn];
void pwtwo(){
	pw[0] = 1;
	for(int i=1; i<pwn; i++){
		pw[i] = (pw[i-1]*2)%mod;
	}
}


ll gcdExtended(ll a, ll b, ll *x, ll *y); 
  
ll modInverse(ll a, ll m) 
{ 	
	if(a==1)
		return 1;
	//cout<<"mi "<<a<<" "<<m<<" ";
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    if (g != 1){
        //cout << "Inverse doesn't exist"<<endl; 
        return -1;
    }
    else
    { 
        // m is added to handle negative x 
        ll res = (x%m + m) % m; 
        //cout<<res<<endl;
        return res;
        // cout << "modular multiplicative inverse is " << res; 
    } 
} 
  
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

ll fact[1010];
ll init(){
	fact[0] = 1;
	for(int i=1; i<1010; i++)
		fact[i] = (fact[i-1]*i)%mod;
}

ll ncr(ll n, ll r){
	ll ans = fact[n];
	if(r>n)
		return 0;
	//if(r!=0)
	ans = (ans*modInverse(fact[r], mod))%mod;
	// if(n-r!=0)
	ans = (ans*modInverse(fact[n-r], mod))%mod;

	return ans;
}

int main(){
	// finput;
	// foutput;
	fast;

	ll n, k, i, j, x, m;
	// ll ans = 0ll;
	cin>>n;

	bool dp[n+1][n+1][n+1];
	char a[n+1][n+1];

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			cin>>a[i][j];
			dp[1][i][j] = true; 
		}
	}

	for(i=2; i<=n; i++){
		for(j=0; j<n; j++){
			for(k=0; k<n; k++){
				// cout<<a[j][k]<<" "<<a[(j+i-1)%n][(k+i-1)%n]<<" "<<a[j][(k+i-1)%n]<<" "<<a[(j+i-1)%n][k]<<endl;
				if(a[j][(k+i-1)%n]==a[(j+i-1)%n][k] 
					&&	dp[i-1][j][k] && dp[i-1][(j+1)%n][(k+1)%n] ){
					dp[i][j][k] = true;
					// cout<<"t "<<i<<" "<<j<<" "<<k<<endl;
				}
				else{
					dp[i][j][k] = false;
					// cout<<"f "<<i<<" "<<j<<" "<<k<<endl;

				}
			}
		}
	}

	int ans = 0;

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(dp[n][i][j])
				ans++;

	cout<<ans;

	return 0;
}