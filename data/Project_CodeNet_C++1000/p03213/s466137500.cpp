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
int main() {
	#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
	srand(chrono::steady_clock::now().time_since_epoch().count());
	off;
	cin>>n;
	int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	VL fact(25,0);
	for(int i=2;i<=n;i++){
		int t = i;
		for(int j = 0;j<25;j++){
			while((t % primes[j]) == 0){
				t /= primes[j];
				fact[j]++;
			}
		}
	}
	LL ans = 0;
	
	int a = 0, b = 0, c = 0, d = 0, e=0;
	for(int i = 0;i<25;i++){
		if(fact[i] >= 2)
			a++;
		if(fact[i] >= 4)
			b++;
		if(fact[i] >= 14)
			c++;
		if(fact[i] >= 24)
			d++;
		if(fact[i] >= 74)
			e++;
	}
	// cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<"\n";
	// case 1 -> (2, 24)
	ans += d*(a-1);
	// + (d * (d-1))/2;
	
	// case 2 -> (4, 14)
	ans += c*(b-1);
	// + (c*(c-1))/2 ;
	
	// case 3 -> (2, 4, 4)
	// ans += ((b*(b-1))/2)*(a - b) + (b * (b-1) * (b-2))/6;
	ans += (b * (b-1) * (a-2))/2;

	ans += e;
	cout<<ans;
  	return 0;
}