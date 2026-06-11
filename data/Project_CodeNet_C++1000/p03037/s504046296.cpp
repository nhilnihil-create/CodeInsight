#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, m, ans = 0;
	cin>> n>>m;
	int lmax = 0, rmin =n;
	for(int i=0;i<m;i++){
		int l, r;
		cin>>l>>r;
		if(lmax < l) lmax = l;
		if(r < rmin) rmin = r;
	}
	if(rmin<lmax){
		ans = 0;
	}else{
		ans = rmin - lmax + 1;
	}
	cout<<ans<<endl;
}