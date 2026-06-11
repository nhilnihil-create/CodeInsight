#pragma GCC optimize("Ofast",3,"inline")
#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define m_p make_pair
#define y1 ygftgfgcdtfgxffgx
#define y2 yfdsesgvtyghftfvv
#define x1 xvyr6cf6fgcfgf676
#define x2 xcr6rfc5r66y6r6fr
#define up_bound upper_bound
#define low_bound lower_bound
#define next_per next_permutation
#define pb push_back
#define i_to_s to_string
typedef priority_queue<int> p_queue;
typedef priority_queue<int, vector<int>, greater<int> > min_p_queue;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int mon[20]={31,28,31,30,31,30,31,31,30,31,30,31};
ll gcd(ll x,ll y){return ((y==0)?x:gcd(y,x%y));}
p_queue q;
int n,a[100010],b[100010];
ll sum,res;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	for(int i=0;i<n;i++)
		if(a[i]<b[i])sum+=(b[i]-a[i]),res++;
		else q.push(a[i]-b[i]);
	while(q.size()&&sum>0)sum-=q.top(),q.pop(),res++;
	if(sum>0)cout<<-1;
	else cout<<res;
	return 0;
}
