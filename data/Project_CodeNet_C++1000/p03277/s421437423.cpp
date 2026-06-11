#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
#define mod 1000000007
using namespace std;
int n,a[114514];
struct BIT{
	vector<int>bit;
	int n;
	BIT(int x){
		bit.resize(x,0);n=x;
	}
	int sum(int x){
		int s=0;
		while(x>0){
			s+=bit[x];
			x-=x&-x;
		}
		return s;
	}
	void add(int x,int y){
		while(x<=n){
			bit[x]+=y;
			x+=x&-x;
		}
	}
};
signed main(){
	cin>>n;
	rep(i,n)cin>>a[i];
	int ok=0,ng=mod;
	while(ng-ok>1){
		int mid=(ok+ng)/2;
		int b[114514];rep(i,n+1)b[i]=0;
		BIT bit(2*n+10);
		int sum=0;
		bit.add(n+1,1);
		rep(i,n){
			if(a[i]>=mid)b[i]+=1;
			else b[i]-=1;
			b[i+1]=b[i];
			b[i]+=n+1;
			sum+=bit.sum(b[i]);
			bit.add(b[i],1);
        }
        if(n%4==0||n%4==3){
		    if(sum>=(n+1)*n/2/2)ok=mid;
		    else ng=mid;
        }else {
            if(sum>(n+1)*n/2/2)ok=mid;
		    else ng=mid;
        }

	}
	cout<<ok<<endl;
}