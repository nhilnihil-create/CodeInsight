#include<bits/stdc++.h>
#define ford(i,a,b) for(int i=(a);i>=b;i--)
#define rep1(i,a,b) for(int i=(a);(i)<=(b);(i)++)
#define rep(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define ll long long
#define N 10005
#define pql priority_queue<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define rev(a,n) reverse(a,a+n)
using namespace std;
int n,a[N],ans;
int main() {
	cin>>n;
	rep(i,0,n){
		cin>>a[i];
		while(a[i]%2==0){
			a[i]/=2;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
