#include<bits/stdc++.h>
#define ford(i,a,b) for(int i=(a);i>=b;i--)
#define rep1(i,a,b) for(int i=(a);(i)<=(b);(i)++)
#define rep(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define ll long long
#define N 200005
#define pql priority_queue<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define rev(a,n) reverse(a,a+n)
using namespace std;
int n,a[N],t[N];
int main() {
	cin>>n;
	rep(i,0,n) {
    	cin>>a[i];
    	t[i]=a[i];
	}
	sort(t,t+n);
	rep(i,0,n) {
    	if(a[i]<t[n/2])cout<<t[n/2]<<"\n";
    	else cout<<t[n/2-1]<<"\n";
	}
	return 0;
}
