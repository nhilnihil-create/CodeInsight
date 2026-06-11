#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e7+5;

int main(){
	int n,sum=0,a=0,b=0,c=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		int l=s.size();
		if(s[0]=='B') b++;
		if(s[l-1]=='A') a++;
		if(s[0]=='B'&&s[l-1]=='A') c++;
		for(int j=1;j<l;j++){
			if(s[j-1]=='A'&&s[j]=='B') sum++;
			//cout<<sum<<" "<<b<<" "<<a<<endl;
		}
	}
	if(b==c&&a==c&&c!=0) sum--;
	cout<<sum+min(a,b)<<endl;
	return 0;
}