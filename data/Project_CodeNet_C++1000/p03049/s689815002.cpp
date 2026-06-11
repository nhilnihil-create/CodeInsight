#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
string s[10005];
vector<string> a,b,c;
int main(){
	int n,num=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		int len=s[i].length()-1;
		if(s[i][0]!='B'&&s[i][len]=='A') a.push_back(s[i]);
		if(s[i][0]=='B'&&s[i][len]=='A') b.push_back(s[i]);
		if(s[i][0]=='B'&&s[i][len]!='A') c.push_back(s[i]);
		for(int j=1;j<=len;j++){
			if(s[i][j]=='B'&&s[i][j-1]=='A') num++;
		}
	}
	int lena=a.size(),lenb=b.size(),lenc=c.size();
	int x=min(lena,1),y=min(lenc,1);
	lena-=x;lenc-=y;
	cout<<min(lena,lenc)+max(0,x+y+lenb-1)+num<<endl;
}