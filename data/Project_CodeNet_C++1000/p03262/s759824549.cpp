#include<bits/stdc++.h>
#define ford(i,a,b) for(int i=(a);i>=b;i--)
#define rep1(i,a,b) for(int i=(a);(i)<=(b);(i)++)
#define rep(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define ll long long
#define N 100005
#define pql priority_queue<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define rev(a,n) reverse(a,a+n)
using namespace std;
int n,x,ans,a[N];
int main() {
	cin>>n>>x;
	rep(i,0,n) cin>>a[i];
	rep(i,0,n) ans=__gcd(ans,abs(x-a[i]));
	cout<<ans; 
	return 0;
}