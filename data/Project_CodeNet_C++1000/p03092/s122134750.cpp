#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'

int n,a,b;
int arr[5005];
int pos[5005];

ll memo[5005][10005];

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	memset(memo,127,sizeof(memo));
	
	cin>>n>>a>>b;
	for (int x=1;x<=n;x++) cin>>arr[x];
	for (int x=1;x<=n;x++) pos[arr[x]]=x*2;

	for (int x=0;x<=2*n;x++) memo[0][x]=0;
	
	for (int x=1;x<=n;x++){
		for (int y=1;y<=2*n+1;y++){
			if (y%2==0 && pos[x]==y){
				memo[x][y]=min(memo[x][y-1],memo[x-1][y]);
			}
			else{
				memo[x][y]=min(memo[x][y-1],memo[x-1][y]+(pos[x]<y?a:b));
			}
			//cout<<x<<" "<<y<<" "<<memo[x][y]<<endl;
		}
	}
	
	cout<<memo[n][2*n+1];
}