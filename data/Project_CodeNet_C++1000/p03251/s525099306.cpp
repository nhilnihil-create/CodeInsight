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
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int x1[n];
    for(int i=0;i<n;++i) cin>>x1[i];
   	int y1[m];
   	for(int i=0;i<m;++i) cin >>y1[i];
   	sort(x1,x1+n);
   	sort(y1,y1+m);
   	if(x1[n-1]<y1[0] && x1[n-1]>x && x1[n-1]<y) cout<<"No War";
   	else cout<<"War";
	return 0;
}