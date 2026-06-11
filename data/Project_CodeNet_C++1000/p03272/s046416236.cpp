#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(a-1);i>=(b);i--)
#define all(x) (x).begin(), (x).end()
const int INF = 1e18;
const int MOD = 1e9+7;
typedef vector<int> vint;
typedef pair<int, int> pint;
typedef vector<string> vstr;
void print() {cout<<'\n';}template<class Head,class...Tail>void print(Head&&head,Tail&&...tail){cout<<head;if(sizeof...(tail)!=0)cout<<" ";print(forward<Tail>(tail)...);}template<class T>void print(vector<T>&vec){for(auto&a:vec){cout<<a;if(&a!=&vec.back())cout<<" ";}cout<<'\n';}template<class T>void print(vector<vector<T>>&df){for(auto&vec:df){print(vec);}}
template<class T=int>T in() {T x;cin>>x;return(x);}
template<class T=int>vector<T> input_to_vector(int n) {vector<T>x;rep(i,n){T a;cin>>a;x.push_back(a);}return(x);}

signed main(){
     int n, i;
     cin >> n >> i;
     print(n - i + 1);
}
