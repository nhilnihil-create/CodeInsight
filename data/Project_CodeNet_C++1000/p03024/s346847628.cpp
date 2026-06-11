#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	string s,t="ooooooooooooooooooo";
	cin>>s;
	s+=t;
	ll cnt=0;
	
	for(int i=0;i<15;i++)if(s[i]=='o')cnt++;
	cout<<(cnt>=8?"YES":"NO");
	return 0;
}
