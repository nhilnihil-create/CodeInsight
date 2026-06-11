#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
	string s;
	cin>>s;
	bool flag1=false;
	bool flag2=false;
	bool flag3=false;
	if(s[0]=='A') flag1=true;
	int cnt=0;
	int pos=0;
	for(int i=2; i<s.size()-1; i++){
		if(s[i]=='C'){
			cnt++;
			pos=i;
		}
	}
	if(cnt==1) flag2=true;
	cnt=0;
	for(int i=1; i<s.size(); i++){
		if(i==pos) continue;
		if(isupper(s[i])) cnt++;
	}
	if(cnt==0) flag3=true;
	if(flag1==flag2&&flag2==flag3) cout<<"AC"<<endl;
	else cout<<"WA"<<endl;
}