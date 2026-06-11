#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin>>n;
	int a[n];
	rep(i,n) cin>>a[i];
	int mn=10e9+1;
	int mx=0;
	rep(i,n){
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	cout << mx-mn << endl;
}