#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) (a).size() 
#define all(c) (c).begin(),(c).end()
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,n) for(int i=1;i<=n;i++)
#define ford(i,n) for(int i=n;i>=0;i--) 
#define REP(i,a,n) for(int i=a;i<n;i++)
#define foreach(itr,c) for(__typeof((c).begin(),(c).end())itr=c.begin();itr!=c.end();itr++) 
#define fill(a,b) memset(a,b,sizeof(a))
#define re return
#define INF 1e9
#define LINF 1e18
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi > vpi; 
int main(){
	int n;
	cin>>n;
	ll cnt[5]={0,0,0,0,0};
	string s[n];
	rep(i,n){
		cin>>s[i];
		if(s[i][0]=='M'){
			cnt[0]++;
		}
		else if(s[i][0]=='A'){
			cnt[1]++;
		}
		else if(s[i][0]=='R'){
			cnt[2]++;
		}
		else if(s[i][0]=='C'){
			cnt[3]++;
		}
		else if(s[i][0]=='H'){
			cnt[4]++;
		}
	}
	ll ans=0;
	for(int i=0;i<5;i++){
		for(int j=i+1;j<5;j++){
			for(int k=j+1;k<5;k++){
				ans+=cnt[i]*cnt[j]*cnt[k];
			}
		}
	}
	cout<<ans;
	re 0;
}