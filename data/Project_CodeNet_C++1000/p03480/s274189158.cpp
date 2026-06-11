#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(a,n) rep(i,0,n){ cout<<(i ? " ":"")<<a[i]; }cout<<endl;
#define pprint(a,m,n) rep(j,0,m){ print(a[j],n); }
const int mod = 1e9+7;
const int size=1e5;
const int INF=1e9;
int main(){
	string s;cin>>s;
	int ans=s.size();int temp=s.size();
	rep(i,1,s.size()){
		if(s[i]!=s[i-1]) ans=min(ans,max(i,temp-i));
	}cout<<ans<<endl;
}