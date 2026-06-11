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
    int ar[3];
    for(int i=0;i<3;++i) cin>>ar[i];
    int mx=max({ar[0],ar[1],ar[2]});
    cout<<accumulate(ar,ar+3,mx*9);
	return 0;
}