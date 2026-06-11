#pragma GCC optimize "-O3"
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define LSOne(S) (S & (-S))
#define ll long long
#define two pair<int,int>
#define twoll pair<ll,ll>
#define four pair<two,two>
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define y1 y1922
#define INF 1000000000000000000
#define P 1000000007
#define lmax 1000000000
#define nn 1000003
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define f first
#define s second
#define vi vector<int>
#define vll vector<ll>
#define vtwo vector<two>
#define ALL(container) (container).begin(), (container).end()
#define sz(container) (int)(container.size())
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define mid(a,b) (a+b>>1)
#define minN 0
#define maxN 10000000
#define na(x) ((x)<P?(x):(x)-P)
#define ab(a) (-(a)<(a)?(a):-(a))
#define FAST std::ios::sync_with_stdio(false)
#define xRand mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define rnd rng
#define IT iterator
typedef
tree<
  int,// aq pair<int,int> shegidzlia
  null_type,
  less/*_equal*/<int>,// aqac
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;
// '_equal' mashin ginda roca multiset gchirdeba
template<class key, class value,class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
ordered_map<int, int> my_map;
inline int rin(){
	int x=0,w=1;char ch=getchar();
	while ((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if (ch=='-') w=0,ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return w?x:-x;
}
inline int bin(){
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}
int fen[400005], mas[400005], val[400005];
void modify(int pos)
{
	for (; pos < 400005; pos += pos & -pos)
		fen[pos]++;
}
int query(int pos)
{
	int Sum = 0;
	for (; pos; pos -= pos & -pos)
		Sum += fen[pos];
	return Sum;
}
int n;
int main(){FAST;xRand;
cin>>n;
for (int i = 0; i < n; i++)
	cin>>mas[i];
int l = 0, r = 1e9, ans = 0;
while (l <= r){
	memset(fen, 0, sizeof(fen));
	int m = l + r >> 1;
	ll sum = 0;
	modify(n + 1);
	for (int i = 0; i < n; i++){
		val[i] = (i ? val[i - 1] : 0) + (mas[i] >= m ? 1 : -1);
		sum += query(val[i] + n + 1);
		modify(val[i] + n + 1);
	}
	if (sum >= (ll)n * (n + 1) / 2 - sum){
		ans = m;
		l = m + 1;
	}
	else
		r = m - 1;
}
cout<<ans<<endl;
}
/*

                   *         *
                  * *       * *
                 *   *     *   *
                *     *   *     *
                 *   *   * *   *
                  *   *   *   *
                   *   * *   *
                     *  *   *
					   *  *


*/

