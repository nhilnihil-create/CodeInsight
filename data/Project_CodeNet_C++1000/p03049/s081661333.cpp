#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int n;cin>>n;
	string s[n];
	int a=0,b=0,c=0,cnt=0;
	rep(i,n){
		cin>>s[i];
		if(s[i][0]=='B'&&s[i][s[i].size()-1]=='A') c++;
		else if(s[i][s[i].size()-1]=='A') a++;
		else if(s[i][0]=='B') b++;
		for(int j=0;j<s[i].size()-1;j++){
			if(s[i][j]=='A'&&s[i][j+1]=='B') cnt++;
		}
	}
	//cout<<a<<" "<<b<<" "<<c<<"\n";
	if(a+b==0&&c>0) cnt+=c-1;
	else cnt+=c+min(a,b);

	cout<<cnt<<"\n";
}