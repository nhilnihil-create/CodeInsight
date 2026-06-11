#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define puts(i) cout<<i<<endl
#define pi 3.14159265358979323846264338
#define pb push_back
#define mkp make_pair
#define INF 10000000000000000000
using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;

ll divisor=1000000007;

int main(){
	int n;
	cin>>n;
	int sum=0,mx=0;;
	int a[n];
	rep(i,n){
		cin>>a[i];
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	if(sum-mx>mx){
		puts("Yes");
	}else{
		puts("No");
	}
}
