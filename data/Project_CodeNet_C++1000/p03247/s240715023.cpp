//code by lynmisakura.wish to be accepted
/****************************/
#include<bits/stdc++.h>
using namespace std;
/***************************/
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vpi;

const long long Mod = 998244353;
const long long mod = 1000000007;
const long long INF = 10000000000000;

#define pb push_back
#define mp make_pair
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(int i = 0;i < n;i++)
#define rep(i,n) for(int i = 0;i < n;i++)
	
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, int mo) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }
 
#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
long long dp[150010];
/***************************/

int n;

long long X[1010],Y[1010];
long long dx[] = {1,0,-1,0};
long long dy[] = {0,1,0,-1};
char direct[] = {'L','D','R','U'};

int main(void){
	scanf("%d",&n);
	bool odd;
	bool check = true;
	rep(i,n){
		scanf("%d%d",&X[i],&Y[i]);
		
		if((X[0] + Y[0])%2!=0)odd = true;
		else odd = false;
		
		if(odd != ((X[i]+Y[i])%2 != 0)){
			check = false;
		}
	}
	if(!check){
		cout << -1 << endl;
		return 0;
	}
	
	/*vector<ll> a;
	if(odd){
		rep(i,31) a.push_back(qp(2,i));
	}else{
		//a.push_back(1);
		rep(i,31) a.push_back(qp(2,i));
		rep(i,n){X[i]--;} //1左に平行移動しておく、あとはoddの場合と一緒
	}*/
	
	if(!odd) rep(i,n) X[i]--;
	
	if(odd)cout << 31; else cout << 32;cout << endl;
	if(!odd) cout << 1 << endl;
	rep(i,31) cout << qp(2,i) << endl;
	
	for(int i = 0;i < n;i++){
		string ans = "";
		int x = X[i],y = Y[i];
		for(int j = 30;j >= 0;j--){
			long long l = qp(2,j);
			for(int k = 0;k < 4;k++){
				long long nx = x + dx[k]*l,ny = y + dy[k]*l;
				if(abs(nx) + abs(ny) <= l - 1){
					x = nx,y = ny;
					ans.push_back(direct[k]);
					break;
				}
			}
		}
		reverse(all(ans));
		if(!odd)cout << 'R';
		cout << ans << endl;
	}
}