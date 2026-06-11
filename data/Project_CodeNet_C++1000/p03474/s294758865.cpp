#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int a,b; cin>>a>>b;
	int k=a+b+1;
	string s; cin>>s;
	int cnt=0;
	rep(i,k){
		if(s[i]=='-') cnt++;
	}
	if(cnt==1&&s[a]=='-') cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}