// "header" {{{
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <tuple>
#include <iomanip>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int> 
#define int int64_t
#define Fixed fixed << setprecision(10)
#define moke_pair make_pair
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const long long mod = 1000000007;

template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }

template <class T> using min_heap = priority_queue<T,vector<T>,greater<T> >;
template <class T> using max_heap = priority_queue<T>;
template <class T,class U> using umap = unordered_map<T,U>;
template <class T> inline int getint(T s){ 
    int n;
    cout << s;
    cin >> n;
    return n;
}

inline int64_t updiv(int64_t n,int64_t d){
    return ((n + d -1) / d);
}
/*
inline double Sqrt( const double &x) 
{
	double         xHalf = 0.5 * x;
	int64_t  tmp   = 0x5FE6EB50C7B537AAl - ( *(int64_t*)&x >> 1);
	double         xRes  = * (double*)&tmp;

	xRes *= ( 1.5 - ( xHalf * xRes * xRes ) );
	xRes *= ( 1.5 - ( xHalf * xRes * xRes ) );
	xRes *= ( 1.5 - ( xHalf * xRes * xRes ) );
	xRes *= ( 1.5 - ( xHalf * xRes * xRes ) );
	return xRes * x;
}
*/
// }}}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    int k,n;
    vector<string> res;
    
    cin >> s >> k;
    n = s.size();

    rep(i,n){
        reps(j,k){
            if(i + j <= n){
                res.emplace_back(s.substr(i,j));
            }
        }
    }

    sort(all(res));
    res.erase(unique(all(res)),res.end());

    cout << res[k-1] << '\n';

    return 0;
}
