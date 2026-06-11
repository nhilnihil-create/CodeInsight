/* --- author: dxm --- */
#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
inline void Fail(){printf("-1");exit(0);}

const int maxn=300005;
int n,a,b,res[maxn];

int main(){
	scanf("%d%d%d",&n,&a,&b);
	if(a+b>n+1||1LL*a*b<n)Fail();
	int now=n-1,c=a,d=n-1;
	while(d-b+1>=c){
		for(int i=d-b+1;i<=d;i++)res[i]=now,now--;
		d-=b;c--;
	} 
	for(int i=c-1;i<=d;i++)res[i]=now,now--;
	for(int i=c-2;i>=0;i--)res[i]=now,now--;
	rep(i,n)printf("%d ",res[i]+1);
	return 0;
}

/*
Input:
-----------------
Output:
*/