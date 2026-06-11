#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=32e4;

char s[N];

int main(){
	ios::sync_with_stdio(0);
	cin>>s;
	int n=strlen(s);
	int c1=0,c2=0;
	for(int i=n/2+1;i<n;i++){
		if(s[i]==s[i-1])c1++;
		else break;
	}
	for(int i=(n-1)/2-1;i>=0;i--){
		if(s[i]==s[i+1])c2++;
		else break;
	}
	if(n%2==0 && s[n/2]!=s[n/2-1])c1=-1;
	//cout<<c1<<' '<<c2<<'\n';
	cout<<n/2+min(c1,c2)+1;
	return 0;
}
