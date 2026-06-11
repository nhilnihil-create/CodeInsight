#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int a,b; cin>>a>>b;
	int cnt=0;
	for(int i=a; i<=b; i++){
		string s1=to_string(i);
		string s2=to_string(i);
		reverse(s1.begin(),s1.end());
		if(s1==s2) cnt++;
	}
	cout<<cnt<<endl;
}