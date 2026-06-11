#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,res;
char s[500005];
int main() {
	cin>>s;
	n=strlen(s);
	res=n;
	for(int i=1; i<n; i++) {
		if(s[i]!=s[i-1])
			res=min(res,max(i,n-i));
	}
	cout<<res;
}