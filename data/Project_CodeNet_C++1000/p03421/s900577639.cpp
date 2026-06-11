#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n,a,b;cin>>n>>a>>b;
	vector<int>seq;int cnt=0,cur=0,tmp=0;
	if(a+b>n+1||a*b<n)	
	{cout<<-1<<endl,exit(0);}
	if(a==1){for(int i=0;i<n;i++)seq.push_back(n-i);
	for(auto&& w:seq)cout<<w<<((&w==&seq.back())?"\n":" ");
	return 0;}
	vector<int>v;
	v.push_back(b);	
	int m=(n-b)/(a-1),r=(n-b)%(a-1);
	for(int i=0;i<a-1;i++)v.push_back(m+(i<r));
	int acm=0;
	for(auto&& w:v){
	for(int i=0;i<w;i++){
		seq.push_back(acm+w-i);		
	}acm+=w;
	}
	for(auto&& w:seq)cout<<w<<((&w==&seq.back())?"\n":" ");

}
