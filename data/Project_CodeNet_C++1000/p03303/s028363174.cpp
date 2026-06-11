#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define elif else if
using namespace std;
string s;
int w,i=0;
signed main()
{
	cin>>s>>w;
	while(1){
		cout<<s[i];
		i=i+w;
		if(i>=s.size()){
			break;
		}
	}
}