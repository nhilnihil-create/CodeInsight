#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
#include<unordered_map>
#define int long long
const int inf=1145141919810893;
const int mod=1000000007;
using namespace std;
template<class T>bool chmin(T &a,const T &b){
	if(a>b){
		a=b;
		return true;
	}
	return false;
}
template<class T>void debug(T *a,int l,int r,const char *name){
	for(int i=l;i<r;i++)
		cout<<name<<"["<<i<<"]="<<a[i]<<endl;
}
int p[500];
signed main(){
	int i,j;
	string s;
	cin>>s;
	if(s.size()==1){
		cout<<"YES"<<endl;
		return 0;
	}
	if(s.size()==2){
		if(s[0]!=s[1])
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		return 0;
	}
	int p[3]={};
	for(auto c:s)
		p[c-'a']++;
	sort(p,p+3);
	p[2]-=p[0];
	p[1]-=p[0];
	if(p[2]<=1&&p[1]<=1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}