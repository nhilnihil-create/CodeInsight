#include<bits/stdc++.h>
#define ford(i,a,b) for(int i=(a);i>=b;i--)
#define rep1(i,a,b) for(int i=(a);(i)<=(b);(i)++)
#define rep(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define ll long long
#define N 105
#define pql priority_queue<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define rev(a,n) reverse(a,a+n)
using namespace std;
int main() {
	ll n,y;
	cin>>n>>y;
	rep1(i,0,n) rep1(j,0,n-i) {
		int k=n-i-j;
		if(10000*i+5000*j+1000*k==y){
			cout<<i<<" "<<j<<" "<<k;
			return 0;
		} 
	}
	cout<<"-1 -1 -1"; 
	return 0;
}
