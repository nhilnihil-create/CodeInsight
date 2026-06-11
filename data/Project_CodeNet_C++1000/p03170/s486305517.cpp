//Krunal_Mathukiya
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define li long int
#define pb push_back
#define mkp make_pair
#define nikalL return
#define chalavo continue
#define basHo break
#define umap unordered_map
#define fr(i,s,n) for(int i=s;i<=n;++i)
#define frr(i,s,n) for(int i=s;i>=n;--i)
#define jaldiKarNe ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
// 1-> taro
// 0-> jiro
int n;
int arr[102];
int dp[100005][2];
int vis[100005][2];
int fn(int k,int turn) {
	cout<<k<<" "<<turn<<endl;
	if(k<arr[1]) {
		if(turn) return 0;
		return 1;
	}
	if(vis[k][turn]) return dp[k][turn];
	vis[k][turn]=1;
	if(turn) { //taro
		int win=0;
		int loose=0;
		fr(i,1,n) {
			if(fn(k-arr[i],1-turn)) win++;
			else loose++;
		}
		if(win) return dp[k][turn]=1;
		else return dp[k][turn]=0;
	}
	else { //jiro
		int win=0;
		int loose=0;
		fr(i,1,n) {
			if(fn(k-arr[i],1-turn)) loose++;
			else win++;
		}
		if(win) return dp[k][turn]=0;
		else return dp[k][turn]=1;
	}
}
int main(){
//	jaldiKarNe;
	int K;
	cin>>n>>K;
	fr(i,1,n) cin>>arr[i];
	fr(k,0,K) {
		fr(turn,0,1) {
//			if(arr[1]>k) {
//				if(turn) dp[k][turn]=0;
//				else dp[k][turn]=1;
//				continue;
//			}
			if(turn) { //taro
				int win=0;
				int loose=0;
				fr(i,1,n) {
					if(k<arr[i]) {
						loose++;
						break;
					}
					if(dp[k-arr[i]][1-turn]) win++;
					else loose++;
				}
				if(win) dp[k][turn]=1;
				else dp[k][turn]=0;
			}
			else { //jiro
				int win=0;
				int loose=0;
				fr(i,1,n) {
					if(k<arr[i]) {
						loose++;
						break;
					}
					if(dp[k-arr[i]][1-turn]) loose++;
					else win++;
				}
				if(win) dp[k][turn]=0;
				else dp[k][turn]=1;
			}
		}
	}
	int ans=dp[K][1];
	if(ans) cout<<"First";
	else cout<<"Second";
}
