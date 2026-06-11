#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,n,y0,x0;
	string s,t;
	cin>>h>>w>>n>>y0>>x0>>s>>t; y0--; x0--;

	bool ok=true;
	int p=y0;
	rep(i,n){
		if(s[i]=='U'){
			p--;
			if(p<0) ok=false;
		}
		if(t[i]=='D') p=min(p+1,h-1);
	}
	p=y0;
	rep(i,n){
		if(s[i]=='D'){
			p++;
			if(p>=h) ok=false;
		}
		if(t[i]=='U') p=max(p-1,0);
	}
	p=x0;
	rep(i,n){
		if(s[i]=='L'){
			p--;
			if(p<0) ok=false;
		}
		if(t[i]=='R') p=min(p+1,w-1);
	}
	p=x0;
	rep(i,n){
		if(s[i]=='R'){
			p++;
			if(p>=w) ok=false;
		}
		if(t[i]=='L') p=max(p-1,0);
	}
	puts(ok?"YES":"NO");

	return 0;
}
