#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int m=1e9+7;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    fastio
 	int a[3];
 	cin>>a[0]>>a[1]>>a[2];
 	sort(a,a+3,greater<int>());
 	cout<<a[0]*10+a[1]+a[2];
	return 0;
}