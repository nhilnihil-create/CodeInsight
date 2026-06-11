#include <bits/stdc++.h>
#define N 55
using namespace std;
int a[2*N],k,n,m,x,y,o,sum,ans;
vector<int>b;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<=min(n,k);i++){
		for(int j=0;j<=min(n,k);j++){
			if(i+j>n||i+j>k)break;
			b.clear();
			for(int l=0;l<i;l++)b.push_back(a[l]);
			for(int l=0;l<j;l++)b.push_back(a[n-1-l]);
			sort(b.rbegin(),b.rend());
			sum=0;
			for(int l=0;l<i+j;l++)sum+=b[l];
			ans=max(ans,sum);
			x=k-i-j;y=i+j-1;
			while(x>0&&b.size()>0&&b[y]<0){
				sum-=b[y];
				y--;
				x--;
			}
			ans=max(ans,sum);
		}
	}
	cout<<ans<<endl;
	return 0;
}