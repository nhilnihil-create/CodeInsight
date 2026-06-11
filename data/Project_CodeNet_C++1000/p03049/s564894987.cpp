#include<bits/stdc++.h>
using namespace std;
int cntA,cntB,cntAB;
char s[15];
signed main(){
	int n,len,ans=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>(s+1);len=strlen(s+1);
		for(int j=1;j<len;++j)
			ans+=(s[j]=='A' && s[j+1]=='B');
		if(s[1]=='B' && s[len]=='A') ++cntAB;
		else if(s[1]=='B') ++cntB;
		else if(s[len]=='A') ++cntA;
	}
	if(cntAB){
		ans+=cntAB-1+(cntA>0)+(cntB>0);
		if(cntA>0) --cntA;
		if(cntB>0) --cntB;		
	} 
	ans+=min(cntA,cntB);
	cout<<ans;
	return 0;
}