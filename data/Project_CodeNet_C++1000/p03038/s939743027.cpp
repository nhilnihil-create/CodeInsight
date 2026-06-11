
// Problem : D - Integer Cards
// Contest : AtCoder - AtCoder Beginner Contest 127
// URL : https://atcoder.jp/contests/abc127/tasks/abc127_d
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*                                   *MELLOW THE PANDA*
  `||||||||||||||||||||||!!!||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  `||||||||||||||||||!''      !!||||pp@@@@@@@@@@@@@@@@@@@@@@||||||!'````````||||||||||||||||
   |||||||||||||||!'`         ,g@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@L           `|||||||||||||||
   '||||||||||||'`         ,p@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@           `||||||||||||||
   '|||||||||||'         j@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@w          ``||||||||||||
   '||||||||||`        ,g@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,         `||||||||||||
   ||||||||||'       ,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@L        `|||||||||||
   '|||||||||       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@p      `'||||||||||
   '|||||||||;,   /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,   `<|||||||||||
   '|||||||||||!;p@@@@@@@@M*     **%@&@F***********&@@@@@@N%@@@@@@@@@@@@@@@@w!||||||||||||||
   '||||||||||||j@@@@@@@N  |!"*!,@@@@@[            &@@&@@m        ?@@@@@@@@g||||||||||||||||
   '||||||||||||]@@@@@@@  ||  #r)@@@@@@$,         g@@@@@@@@|"""!|; ]@@@@@@@@@@||||||||||||||
   `||||||||||||]@@@@@@|  ||   g@@@@@@@@@@p    ,@@@@@&@@@@@@|#L !|  %@@@@@@@@@k|||||||||||||
   `||||||||||||]@@@@@@    `||$@@@@N@@@@@@&@$@@$@@@@@@@@@@@@@   ||  ]%@@@@@@@@H|||||||||||||
   `||||||||||||]@@@@@@      ^@@@@@NM@@@@@@@@@ |@@@@@@@@@@@@@@''`    %@@@@@@%%||||||||||||||
    ||||||||||||%@@@@@@      ]B@@@@@@|&@@@@@@@M$@@@@@@@@@/@@@@@      ]@@@@@@@%!!!|||||||||||
    '|||||||||||]@@@@@@o      @@@@@@@@@|N@@@@@ @@@@@@@@@|@@@@@@     ]@@@@@@@%  ```'|||||||||
    '|||||||||||]@@@@@@@      ]@@@@@@@@@@]%@N@ Q@@@@%@[]@@@@@@N    p@@@@@@%M        `|||||||
    `||||||||||||]@@@@@@@;     %N@@@@@@@@@@@@Lj@@gg@@@@@@N@@@N   )@@@@@@@@F          '||||||
    `|||||||||||||]%@@@@@@@r    %@@@@@@@@@@@@@@@@@@@@@@@@@@@K   ]@@@@@@@@h          '`||||||
    `||||||||||||||]@%N%N@@@gm,,  j%@@@@@@@@@@@@@@@@@@@@@%h  ;p@@@@@@@@@F            `||||||
    `|||||||||||||||j%@@@@@@@@@p"..                    ,,;g@@@@@@@@@@*"              `||||||
    `||||||||||||||||||]%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@k@]N"                 '||||||
    `|||||||||||||||'``'"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@**'```                        |||||||
    `||||||||||||||'|`     '*@@@@@@@@@@@@@@@@@@@``                                   y||||||
    `'||||||||||||'`            ''"**|||||||||||                                    j|||||||
    ``|||||||||||`                     `'`'|jk*                                   ,j||||||||
    `'|||||||||||                          '`                                   ;p||||||||||
    ``||||||||||'                                                                 `'*j||||||
    ``|||||||||||                                    						              ||
___________________________________________________________________________________________________________________________________________________________*/
#include <bits/stdc++.h> 
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define l00p(i, a, b) for (int i=a; i<(b); i++)
#define loop(i, a) for (int i=0; i<(a); i++)
#define rep1(i,a,b) for (int i = (b)-1; i >= a; i--)
#define rep(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define imax INT_MAX
#define imin INT_MIN
//#define MOD 998244353
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

 
const int MOD = 1000000007;
const char nl = '\n';
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
ll gcd(ll a, ll b){if(b==0)return a;return gcd(b, a%b);}
ll lcm(ll a, ll b){return a*b/gcd(a, b);}

int main() {
	 
	ios_base::sync_with_stdio(0); cin.tie(0); 
	ll n,m;
	cin>>n>>m;
	vl v(n);
	ll sum=0;
	loop(i,n)
	cin>>v[i],sum+=v[i];
	sort(all(v));
	vpl b(m);
	loop(i,m)
	cin>>b[i].second>>b[i].first;
	sort(b.rbegin(),b.rend());
	int c=0;
	loop(i,m)
	{
		for(int j=0;j<b[i].second&&c<n;j++,c++)
		{
			if(b[i].first<v[c])
			{
				cout<<sum;
				return 0;
			}
			sum+=b[i].first-v[c];
		}
	}
	cout<<sum;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343