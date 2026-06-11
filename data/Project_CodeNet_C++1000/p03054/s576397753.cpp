#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll h,w,n,sy,sx;
	cin>>h>>w>>n>>sy>>sx;
	string s,t;
	cin>>s>>t;
	bool ch=true;
	ll cy=sy;ll cx=sx;
	for(ll i=0;i<n;i++){
		if(s[i]=='D'){
			cy++;
			if(cy==h+1){
				ch=false;
			}
		}
		if(t[i]=='U'){
			cy--;
			if(cy==0){
				cy++;
			}
		}
	}
    cy=sy;cx=sx;
	for(ll i=0;i<n;i++){
		if(s[i]=='U'){
			cy--;
			if(cy==0){
				ch=false;
			}
		}
		if(t[i]=='D'){
			cy++;
			if(cy==h+1){
				cy--;
			}
		}
	}    cy=sy;cx=sx;
	for(ll i=0;i<n;i++){
		if(s[i]=='L'){
			cx--;
			if(cx==0){
				ch=false;
			}
		}
		if(t[i]=='R'){
			cx++;
			if(cx==w+1){
				cx--;
			}
		}
	}    cy=sy;cx=sx;
	for(ll i=0;i<n;i++){
		if(s[i]=='R'){
			cx++;
			if(cx==w+1){
				ch=false;
			}
		}
		if(t[i]=='L'){
			cx--;
			if(cx==0){
				cx++;
			}
		}
	}		
	cout << (ch? "YES":"NO");
	// your code goes here
	return 0;
}