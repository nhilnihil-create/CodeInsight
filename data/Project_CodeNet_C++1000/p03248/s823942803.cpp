#include<iostream>
#include<cstring>
using namespace std;
char s[100005];
int n;
signed main(){
	cin>>(s+1);
	n=strlen(s+1);
	if(s[1]=='0'||s[n]=='1') return cout<<-1,0;
	for(int i=1;i<n;++i)if(s[i]^s[n-i]) return cout<<-1,0;
	int now=1;
	for(int i=2;i<=n;++i){
		cout<<now<<" "<<i<<endl;
		if(s[i-1]=='1')now=i;
	}
	return 0;
} 