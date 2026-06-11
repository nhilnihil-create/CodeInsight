#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define reset(x,n) memset((x),(n),sizeof(x))
#define all(n) (n).begin(),(n).end()
#define pb push_back
#define IOS ios::sync_with_stdio(0),cin.tie(0);
bitset<10005> ok[5005];
int stick[] = {0,2,5,5,4,5,6,3,7,6};
bool used[10];
int n,m;

int main(){
	ok[0][0] = 1;
	cin>>n>>m;
	for(int i=1,x;i<=m;i++){
		cin>>x;
		used[x] = 1;
		for(int j=1;j<=5000;j++){
			ok[j] = ok[j] | (ok[j-1]<<stick[x]); 
		}
	}	
	int now = n;
	string ans = "";
	int st = 5000;
	while(!ok[st][now]) st--;
	for(int i=st;i>=1;i--){
		for(int j=9;j>=1;j--){
			if(used[j] && now >= stick[j] && ok[i-1][now-stick[j]]){
				ans += j + '0';
				now -= stick[j];
				break;
			}
		}
	}
	cout<<ans<<'\n';	
}
