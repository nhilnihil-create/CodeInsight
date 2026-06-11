#include<bits/stdc++.h>
using namespace std;
int n,k,q;
string s;
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n>>s>>q;
	while(q--){
		cin>>k;
		long long ans=0,dm=0,m=0,d=0;
		for(int i=0;i<n;i++){
			if(s[i]=='D')
				d++;
			if(s[i]=='M')
			{
				dm+=d;
				m++;
			}
			if(s[i]=='C')
				ans+=dm;
			if(i>=k-1){
				int p=i-k+1;
				if(s[p]=='D')
					dm-=m,d--;
				if(s[p]=='M')
					m--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
