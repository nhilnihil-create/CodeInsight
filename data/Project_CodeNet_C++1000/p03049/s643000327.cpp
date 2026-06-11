#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#define ios ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
const int maxn=1e4+100;
string a[maxn];
int main()
{
	ios;
	int n,A=0,B=0,AB=0; cin>>n;
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		int len=a[i].size()-1;
		for(int j=1;j<=len;j++){
			if(a[i][j]=='B'&&a[i][j-1]=='A') sum++;
		}
		if(a[i][0]=='B'&&a[i][len]=='A'){
			AB++; continue;
		}
		if(a[i][0]=='B'){
			B++; continue;
		}
		if(a[i][len]=='A'){
			A++; continue;
		}
	}
	ll ans=0;
	if(AB>0){
		if(A>0||B>0){
			A-=1; B-=1;
			ans+=2;AB-=1;			
		}
		else AB-=1;
	}
	ans+=min(A,B)+AB+sum;
	cout<<ans<<endl;
	return 0;
}