#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define puts(i) cout<<i<<endl;
int main(){
	ll a[3],n;
	cin>>a[0]>>a[1]>>a[2]>>n;
	cout<<(a[0]-a[1])*(n%2==0?1:-1)<<endl;
}
