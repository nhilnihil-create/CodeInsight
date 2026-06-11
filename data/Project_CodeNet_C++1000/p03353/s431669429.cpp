#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);i++) 
#define elif else if
#define pb push_back
#define ll long long
#define mp make_pair
#define all(x) x.begin(),x.end()
//#define x first
//#define y second

using namespace std;
int k;
string s;
set<string>ans;
set<string>::iterator it;
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>s>>k;
	rep2(i,1,min((int)(s.size()+1),6))
	rep(j,s.size()-i+1)
	ans.insert(s.substr(j,i));
	for(it=ans.begin();k>1;it++,k--);
	cout<<*it<<endl;
	return 0;}