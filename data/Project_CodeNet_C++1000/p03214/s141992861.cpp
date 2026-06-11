#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<stdio.h>
#include<vector>
#define int long long
using namespace std;
#define rep(s,i,n) for(int i=s;i<n;i++)
#define c(n) cout<<n<<endl;
#define ic(n) int n;cin>>n;
#define sc(s) string s;cin>>s;
double a[114];
signed main(){
	double n;
	cin>>n;
	int sum=0;
	rep(0,i,n){
		cin>>a[i];
		sum+=a[i];
	}	
	double av=sum/n;
	double di=1145141919810;
	int ans=0;
	rep(0,i,n){
		if(abs(a[i]-av)<di){
			di=abs(a[i]-av);
			ans=i;
		}
	}
	c(ans)
}			