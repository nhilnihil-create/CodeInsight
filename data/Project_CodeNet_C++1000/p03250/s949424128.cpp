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
    int a,b,c;
    cin>>a>>b>>c;
    int ans=max<int>({
    	10*a+b+c,
    	a+b*10+c,
    	a+b+c*10,

    });
    cout<<ans;
	return 0;
}