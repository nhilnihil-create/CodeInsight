#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pi;
priority_queue<pi, vector<pi>, greater<pi> > pq; //min heap

#define dodebug(i, n, arr)	for(int i=0;i<n;++i)	cout<<arr[i]<<" ("<<i<<")\n";

ll gcd(ll a,ll b){	if(b == 0)	return a;return gcd(b,a%b);}
ll binpow(ll n,ll x){	ll ans = 1;while(x){if(x & 1)	ans *= n;n *= n;x >>= 1;}return ans;}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin>>n>>k;
	vector<bool> dp(k+1, false);//true if the person whose chance it is can win.
	vector<int> stones(n, 0);
	for(auto &i:stones)	cin>>i;

	for(int i=0;i<=k;++i){
		for(auto x:stones){
			if(i >= x && !dp[i-x]){
				//if dp[i-x] is false that means if i play a chance and pass it to the other person
				//he loses and i win, therefore dp[i] is true, and vice versa
				dp[i] = true;
			}
		}
	}
	
	cout<<(dp[k]?"First":"Second")<<"\n";

	return 0;
}