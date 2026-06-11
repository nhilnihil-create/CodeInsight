#include<iostream>
#include<cmath>
using namespace std;
long long a[1005],b[1005];
int n,m,cnt;
long long x,y;
char s[45];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if((a[i]+b[i])&1) cnt++;
		else cnt--;
	}
	if(abs(cnt)!=n){
		cout<<-1;
		return 0;
	}
	m=31+(cnt<0);
	cout<<m<<endl;
	for(int i=0;i<=30;i++){
		cout<<(1<<i)<<" ";
	}
	if(cnt<0) cout<<1;
	cout<<endl;
	for(int i=1;i<=n;i++){
		int x=a[i],y=b[i];
		if(cnt<0) s[31]='R',x--;
		int flag=0;
		for(int j=30;j>=0;j--){
			if(abs(x)<abs(y)) swap(x,y),flag^=1;
			if(x>0) x-=(1<<j),s[j]=flag?'U':'R';
			else x+=(1<<j),s[j]=flag?'D':'L';
		}
		cout<<s<<endl;
	}
}