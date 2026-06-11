#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=5005;
int n,a[N];
ll f[N],A,B;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>A>>B;
	fo(i,1,n)cin>>a[i];
	a[n+1]=n+1;
	fo(i,1,n+1){
		int ct=0,ct2=0,mx=0;
		f[i]=1e18;
		fd(j,0,i-1)
			if(a[j]<a[i]){
				if(a[j]<mx){
					++ct2;
					continue;
				}
				f[i]=min(f[i],f[j]+A*ct+B*ct2);
				++ct2;mx=a[j];
			}else ++ct;
	}
	cout<<f[n+1];
}