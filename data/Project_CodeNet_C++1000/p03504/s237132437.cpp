#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M 998244353
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
 
ll A(ll x){
    if(x>=0)return x;
    else return -x;
}
 
ll gcd(ll a, ll b) {
	if (b > a) {
		ll tmp = b;
		b = a;
		a = tmp;
	}
	if (a%b == 0)return b;
	else return gcd(b, a%b);
}

struct edge{
	ll to;
	ll cost;
};

vector<edge>g[100];

ll sum[31][100010];

int main(void){
	ll n,C;
	cin>>n>>C;
	for(int i=0;i<n;i++){
		int s,t,c;
		cin>>s>>t>>c;
		sum[c][s]++;
		sum[c][t+1]--;
	}
	for(int i=1;i<=C;i++){
		for(int j=1;j<100010;j++){
			sum[i][j]=sum[i][j]+sum[i][j-1];
		}
	}
	ll ans = 0;
	for(int j=0;j<100010;j++){
		ll cnt = 0;
		for(int i=1;i<=C;i++){
			if(sum[i][j])cnt++;
		}
		ans = max(ans,cnt);
	}
	cout<<ans<<endl;
    return 0;
}