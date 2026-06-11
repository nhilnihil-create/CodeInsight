#include<bits/stdc++.h>
using namespace std;
signed main(){
	string s;cin>>s;
	int len=s.size();
	bool flag=1;
	for(register int i=1;i<len;i++)
		if(s[i]!='9'){
			flag=0;
			break;
		}
	printf("%d\n",(len-1)*9+s[0]-'0'-1+flag);
	return 0;
}