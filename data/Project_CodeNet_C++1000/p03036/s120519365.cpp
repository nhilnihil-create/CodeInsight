#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int r, d, x0;
	
	cin>> r>>d>>x0;
	vector<int> a(11);
	a[0] = x0;
	for(int i=1;i<=10;i++){
		a[i] = r*a[i-1] - d;
	}
	for(int i=1;i<=10;i++){
		cout<<a[i]<<endl;
	}
}