#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>> n;
	vector<tuple<string,int, int>> asp;
	for(int i=0;i<n;i++){
		string s;
		int p;
		cin>>s>>p;
		asp.emplace_back(s, 100-p, i+1 );
	}
	
	sort(begin(asp),end(asp));
	for(int i=0;i<n;i++){
		cout<< get<2>(asp[i]) <<endl;
	}
}