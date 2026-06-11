#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std; 
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
template <class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_mset;
 
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define F0R(i,a) for(int i = 0; i < a; i++)
#define F0Rd(i,a) for (int i = a - 1; i >=0 ; i--)
#define FORd(i,a,b) for (int i = b - 1; i >= a; i--)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define newl '\n'
 
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define print(x) cout << x << newl;
#define finish(x) return cout << x << "\n", 0;
#define bug(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " " << 
 
//const ll MOD = 998244353;
//const ll INF = 1e9 + 7;

const int MX = 2e5 + 5;
int N;

ll BIT[MX], ans;

//sum[1,k]
ll query(int k){
	ll sum = 0;
	for(;k > 0; k -= k & -k) sum = max(sum, BIT[k]);
	return sum;
}

//arr[k] += x
void update(int k, ll x){
	for(;k <= N; k += k&-k) BIT[k] = max(BIT[k], x);
}

int main(){ FAST
    //ifstream cin("/Users/konwoo/input.txt");
    //ofstream cout("/Users/konwoo/output.txt");

	cin >> N;
	vector<ll> heights(N), a(N);
	F0R(i,N){
		cin >> heights[i];
	}
	F0R(i,N){
		cin >> a[i];
	}


	F0R(i,N){
		ll cur_height = heights[i], cur_beauty = a[i];
		ll dp_ans = query(heights[i] - 1) + cur_beauty;
		update(heights[i],dp_ans);
		ans = max(ans, dp_ans);
	}
	finish(ans);






    return 0;
}
