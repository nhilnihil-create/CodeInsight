#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define SZ(x) ((int)(x).size())
#define fastin ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
int n,a[3010],ans;
int main(){
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
		ans+=(a[i]-1);
	}
	printf("%d\n",ans); 
	return 0;
}
