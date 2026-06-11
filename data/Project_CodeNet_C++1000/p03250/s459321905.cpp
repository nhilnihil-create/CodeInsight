#include <bits/stdc++.h>
using namespace std;


int main(){
	int a,b,c;
	cin>>a;
	cin>>b;
	cin>>c;
	int mx = max({a,b,c});
	int mn = min({a,b,c});
	int ans = mx*10 + mn + (a+b+c - mx - mn);
	cout<< ans <<endl;
}
