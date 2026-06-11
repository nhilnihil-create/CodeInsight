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
ll INF=10000000;
ll a[100010],b[100010];
int n;
ll cnt1,cnt2,x;;
int main() {
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++){
		x+=b[i]-a[i];
		if(a[i]<b[i]){
			if((b[i]-a[i])%2==1)cnt2++;
			cnt1+=(b[i]-a[i]+1)/2;
		}
		else if(a[i]>b[i]) cnt2+=a[i]-b[i];
	}
	if (cnt1<=x&&cnt2<=x)cout<<"Yes";
	else cout<<"No";
}

