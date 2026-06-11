#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define INF 1'000'000'007
#define cases int t;cin>>t;while(t--)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define ff first
#define ss second

#define test4(x,y,z,a) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<"		a is "<<a<<endl;
#define test3(x,y,z) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<endl;
#define test2(x,y) cout<<"x is "<<x<<"		y is "<<y<<endl;
#define test1(x) cout<<"x is "<<x<<endl;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	string s1,s2;
	cin>>s1>>s2;
	ll m=s1.size(),n=s2.size();

	ll dp[m+1][n+1];
	rep(i,0,m+1){
		rep(j,0,n+1){
			if(i==0||j==0){
				dp[i][j]=0;
			}
			else if(s1[i-1]==s2[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	ll i=m,j=n;
	string s="";
	while(i!=0&&j!=0){
		if(s1[i-1]==s2[j-1]){
			s+=s1[i-1];
			i--;
			j--;
		}
		else{
			if(dp[i-1][j]>dp[i][j-1]){
				i--;
			}
			else{
				j--;
			}
		}
	}
	reverse(s.begin(),s.end());
	cout<<s;

	
	
	
	return 0;
}