#include<iostream>
#include<string>
#include<algorithm>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define INF 1e6
using namespace std;

int main(){
	int n;
	string s;
	cin>>n>>s;
	int a[n+1],range[n+1];
	fill(a,a+n+1,0);
	fill(range,range+n+1,0);
	rep(i,s.size()){
		if(s[i]=='W'){
			a[i+1]++;
			a[s.size()+1]--;
		}else{
			a[0]++;
			a[i]--;
		}
	}
	rep(i,s.size()){
		if(i==0)range[i]=a[i];
		else range[i]=range[i-1]+a[i];
	}
	int ans=INF;
	rep(i,s.size()){
		ans=min(ans,range[i]);
	}
	cout<<ans<<endl;
	return 0;
}