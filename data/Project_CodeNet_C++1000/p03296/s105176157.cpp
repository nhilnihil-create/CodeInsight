
	#include <bits/stdc++.h>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstring>
	#include <chrono>
	#include <complex>
	#define endl "\n"
	#define ll long long int
	#define vi vector<int>
	#define vll vector<ll>
	#define vvi vector < vi >
	#define pii pair<int,int>
	#define pll pair<long long, long long>
	#define mod 1000000007
	#define inf 1000000000000000001;
	#define all(c) c.begin(),c.end()
	#define mp(x,y) make_pair(x,y)
	#define mem(a,val) memset(a,val,sizeof(a))
	#define eb emplace_back
	#define f first
	#define s second
	
	using namespace std;
	int main()
	{
		std::ios::sync_with_stdio(false);
		ll n;
		cin>>n;
		ll a[n+1];
		for(int i =1;i<=n;i++){
			cin>>a[i];
		}
		ll ans = 0;
		while(true){
			bool poss=false;
			for(int i =1;i<=n;i++){
				if(i == 1){
					poss |= (a[i] == a[i+1]);
				}
				else if(i == n){
					poss |= (a[i] == a[i-1]);
				}
				else{
					poss |= (a[i] == a[i+1] || a[i]==a[i-1]);
				}
			}
			if(poss==false){
				break;
			}
			ll idx = -1;
			for(int i =2;i<=n-1;i++){
				if(a[i] == a[i-1] && a[i] == a[i+1]){
					idx = i;
					break;
				}
			}
			if(idx != -1){
				set<ll> se;
				se.insert(a[idx-1]);
				se.insert(a[idx+1]);
				se.insert(a[idx]);
				ll gg = -1;
				for(int j = 1;;j++){
					if(se.find(j) == se.end()){
						gg=j;break;
					}
				}
				ans += 1;
				a[idx] = gg;
				continue;
			}
			
					for(int i =2;i<=n-1;i++){
					if(a[i] == a[i-1] || a[i] == a[i+1]){
						idx = i;
						break;
					}
				}
				if (idx != -1){
					set<ll> se;
				se.insert(a[idx-1]);
				se.insert(a[idx+1]);
				se.insert(a[idx]);
				ll gg = -1;
				for(int j = 1;;j++){
					if(se.find(j) == se.end()){
						gg=j;break;
					}
				}
				ans += 1;
				a[idx] = gg;
				continue;
				}
			
				if(a[1] == a[2]){
					ans += 1;
					ll gg = -1;
					for(int j =1;;j++){
						if(j != a[1] && j != a[2]){
							gg=j;break;
						}
					}
					a[1]  = gg;
				}
				else if(a[n]==a[n-1]){
					ans += 1;
					ll gg = -1;
					for(int j =1;;j++){
						if(j != a[n] && j != a[n-1]){
							gg=j;break;
						}
					}
					a[n]  = gg;

				}
				
			
		}
		// for(int i = 1;i<=n;i++){
		// 	cout<<a[i]<<" ";
		// }
		// cout<<endl;
		cout<<ans<<endl;
		return 0;
	}
