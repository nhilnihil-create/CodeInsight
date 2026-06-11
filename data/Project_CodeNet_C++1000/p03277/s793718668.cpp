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
#define ed(V) V&-V
using namespace std;
int n,k;
int T[200005];
int a[100005],srt[100005];
void m_Tree(int x,int t){
	for(int i=x;i<=2*n;i+=ed(i))T[i]+=t;
}
int g_Tree(int e){
	int ret=0;
	for(int i=e;i>0;i-=ed(i))ret+=T[i];
	return ret;
}
bool check(int x){
	for(int i=2*n;i>0;i--)T[i]=0;
	int t=n+1;
	ll cnt=0;
	m_Tree(t,1);
	for(int i=0;i<n;i++){
		t+=a[i]>=x?1:-1;
		cnt+=g_Tree(t);
		m_Tree(t,1);
	}
	return cnt>=(ll)n*(n+1)/2-cnt;
}
int BS(int s,int e){
	if(s==e)return s;
	int m=s+e>>1;
	if(check(m+1))return BS(m+1,e);
	return BS(s,m);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i),srt[i]=a[i];
	sort(srt,srt+n);
	k=unique(srt,srt+n)-srt;
	for(int i=0;i<n;i++)a[i]=lower_bound(srt,srt+k,a[i])-srt;
	printf("%d",srt[BS(0,k-1)]);
}