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
int n,k,a[N],ans;
int main() {
	cin>>n>>k;
	rep(i,0,n) cin>>a[i];
	//数组中肯定有1，所以最后结果肯定是n个1，1在x位，左边为（a-1）/（k-1），右边为 （n-x）/（k-1）
	//加起来得(n-1)/(k-1) 
	ans=(n-1)/(k-1);
	if((n-1)%(k-1)!=0)ans++;
	cout<<ans;
	return 0;
}