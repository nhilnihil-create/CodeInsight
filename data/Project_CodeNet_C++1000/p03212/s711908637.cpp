#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;
typedef vector<LL> 		VL;
typedef unsigned long long int ULL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//Works for forward as well as backward iteration

#define gu getchar
#define pu putchar
#define si(n) cin>>n
#define dout(n) cout<<n<<"\n"
//# define M_PI           3.14159265358979323846264338327950288

#define DRT() int t; si(t); while(t--)

#define PlUSWRAP(index,n) index = (index+1)%n		//index++; if(index>=n) index=0
#define MINUSWRAP(index,n) index = (index + n -1)%n 	//index--; if(index<0) index=n-1
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)	//Round off d to nearest integer

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define off ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// set_name.find_by_order(k) It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time
// set_name.order_of_key(k) It returns to the number of items that are strictly smaller than our item k in O(logn) time.
LL n;
LL len;
string s;
LL dp[11][2][2][2][2];

LL rec(int pos, int sev, int fi, int th, int tight, int zero){
	if(pos >= len && (!sev || !fi || !th))
		return 0;
	if(pos >= len)
		return 1;
	if(dp[pos][sev][fi][th][tight] != -1)
		return dp[pos][sev][fi][th][tight];
	int lim = tight ? (s[pos] - '0') : 9;
	int temp = 0;
	if(zero && (0 <= lim)){
		if(tight && (0 == lim)){
			temp += rec(pos+1, sev, fi, th, 1, 1);
		}
		else{
			temp += rec(pos+1, sev, fi, th, 0, 1);
		}
	}
	if(3 <= lim){
		if(tight && (3 == lim)){
			temp += rec(pos+1, sev, fi, 1, 1, 0);
		}
		else{
			temp += rec(pos+1, sev, fi, 1, 0, 0);
		}
	}
	if(5 <= lim){
		if(tight && (5 == lim)){
			temp += rec(pos+1, sev, 1, th, 1, 0);
		}
		else{
			temp += rec(pos+1, sev, 1, th, 0, 0);
		}
	}
	if(7 <= lim){
		if(tight && (7 == lim)){
			temp += rec(pos+1, 1, fi, th, 1, 0);
		}
		else{
			temp += rec(pos+1, 1, fi, th, 0, 0);
		}
	}
	return dp[pos][sev][fi][th][tight] = temp;
}
int main() {
	#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
	srand(chrono::steady_clock::now().time_since_epoch().count());
	off;
	cin>>s;
	len = s.length();
	for(int i=0;i<11;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				for(int p=0;p<2;p++){
					dp[i][j][k][p][0] = dp[i][j][k][p][1] = -1;
				}
			}
		}
	}
	LL ans = rec(0, 0, 0, 0, 1, 1);
	cout<<ans;
  	return 0;
}