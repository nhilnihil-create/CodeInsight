#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
typedef long long  ll;
typedef long double ld;
typedef pair<ll ,ll > pll;
typedef pair<int ,int > pii;
const ld pi=3.14159265359;
const int maxn=2e5+7;
const int mod=1e9+7;
const ll INF=9223372036854775807;
const int inf=2e9+7; 
/*Almost copy pasted part :)*/

//additional
#define int long long 
//	

int a[maxn];
int p[maxn];

int32_t main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		int b;
		cin>>b;
		a[i]=a[i]-b;
		sum+=a[i];
	}
	if(sum<0){
		cout<<-1<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		p[i]=a[i];
	}
	int i=1,j=n;
	while(i<j){
		if(a[i]==0){
			i++;
		}
		if(a[j]==0){
			j--;
		}
		if(!(i<j))
			break;
		if(a[i]>=0)
			break;
		int p=abs(a[i]);
		int dec=min(a[j],p);
		p-=dec;
		a[j]-=dec;
		a[i]=-p;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=p[i]){
			ans++;
		}
	}
	cout<<ans<<endl;

}