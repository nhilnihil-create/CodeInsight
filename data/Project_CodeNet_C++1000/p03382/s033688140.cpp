#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define INF 1e18
#define MOD 1000000007
#define N 1000005
#define BB(V) V[V.size()-2]
#define ex(V) return printf(V),0
using namespace std;
int a[100005];
int main(){
	int n;
	scanf("%d",&n);
	int mx=0;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		mx=max(mx,a[i]);
	}
	int t=a[0]==mx?1:0;
	for(int i=0;i<n;i++){
		if(abs(a[t]-mx/2)>abs(a[i]-mx/2))t=i;
	}
	printf("%d %d",mx,a[t]);
}