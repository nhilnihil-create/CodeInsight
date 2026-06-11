#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi; 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
const int mod = 1e9+7;
const int maxn = 2e5+10;
const int inf = 0x3f3f3f3f;
int book[maxn];
int pos[30],pre[30];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int n;
	cin>>n;
	rep(i,1,n) {
		cin>>book[i];
	}
	ll ans=0;
	rep(i,1,n) {
		int num=i;
		rep(j,0,20) {
			int xx=1<<j;
			if(xx&book[i]) {
				num=min(num,i-pos[j]);
				pre[j]=pos[j];
				pos[j]=i;
			}
			else {
				num=min(num,i-pre[j]);
			} 
		}
		ans+=num;
	}
	cout<<ans<<'\n';
	return 0;
}
