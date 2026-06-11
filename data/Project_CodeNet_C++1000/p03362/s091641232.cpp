#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
int prime[50010],p;
int main(){
	rep(i,3,50005){
		int flag=1;
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				flag=0;break;
			}
		}
		if(flag&&i%5==1){
			prime[++p]=i;
		}
	}
	int n;cin>>n;
	rep(i,1,n){
		printf("%d%c",prime[i],(i==n)?'\n':' ');
	}
	return 0;
}

