#include <bits/stdc++.h>
using namespace std;
#define F(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;
#define mod 1000000007
int main()
{	
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int w=1;
	// cin>>w;
	while(w--){
		string s,t;
		cin>>s>>t;
		int n=s.size(),m=t.size();
		int arr[n+1][m+1];
		F(i,0,n+1){
			F(j,0,m+1){
				if(i==0||j==0)arr[i][j]=0;
				else{
					if(s[i-1]==t[j-1])arr[i][j]=arr[i-1][j-1]+1;
					else arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
				}
			}
		}
		string ans="";
		int i=n,j=m;
		while(i>0&&j>0){
			if(s[i-1]==t[j-1]){ans=t[j-1]+ans;
			i--;j--;}
			else if(arr[i][j-1]>arr[i-1][j])j--;
			else i--;
		}
		cout<<ans;
	}
}