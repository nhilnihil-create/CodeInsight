#include<bits/stdc++.h>
#define fo(i,w,n) for(int i=(int) w;i<(int) n;i++)
#define qi queue<int>
#define vi vector<int>
#define ll long long
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define fi first
#define se second
#define mem(a,b) memset(a,b,sizeof(a))
#define cpy(a,b) memcpy(a,b,sizeof(a))
#define prq priority_queue
#define foreach(it,c) for(__typeof((c).begin()) it=c.begin();it!=c.end();it++)
using namespace std;
inline ll read(){
	ll x=0;
	int f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	return x*f;
}
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int n,k;
	cin>>n>>k;
	cout<<n-k+1<<endl;
	return 0;
}