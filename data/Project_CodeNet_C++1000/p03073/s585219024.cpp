#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string s; cin>>s;
	int k=s.size();
	int cnta=0, cntb=0;
	rep(i,k){
		char a,b;
		
		if(i%2==0) a='0';
		else a='1';
		if(s[i]!=a) cnta++;
		
		if(i%2==0) b='1';
		else b='0';
		if(s[i]!=b) cntb++;	
	}
	cout<<min(cnta,cntb)<<endl;
}