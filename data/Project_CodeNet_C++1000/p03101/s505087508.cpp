#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++) 
using namespace std;
typedef long long ll;

int main(){
	int H,W,h,w; cin>>H>>W>>h>>w;
	int mx=H*W;
	int mn=W*h+H*w-w*h;
	cout << mx-mn << endl;	
}