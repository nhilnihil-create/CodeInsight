#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {0,1,0,-1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << endl;
}
const int mod = 1e9 + 7;

int main(){
	ll n; cin >> n;
	vl a(n); rep(i,n) cin >> a[i];
	ll ok = 1e6; ll ng = 0;
	while(ok-ng>1){
		ll mid = (ok+ng)/2;
		stack<P> st;
		bool flag = true;
		rep(i,n){
			if(mid == 1){
				if(i<n-1 && a[i+1] < a[i]){
					flag = false;
					break;
				}
			}
			if(st.empty()) st.emplace(a[i],1);
			else{
				if(st.top().first > a[i]){
					while(!st.empty() && st.top().first > a[i]){
						st.pop();
					}
					if(st.empty()){
						st.emplace(a[i],2);
						continue;
					}
					if(st.top().first == a[i]){
						ll pre = a[i];
						bool emp = false;
						while(st.top().first==pre && st.top().second==mid){
							pre--;
							if(pre == 0) break;
							st.pop();
							if(st.empty()){
								emp = true;
								st.emplace(pre,2);
								break;
							}
						}
						if(pre == 0){
							flag = false;
							break;
						}
						if(emp) continue;
						if(st.top().first == pre){
							P p = st.top(); st.pop();
							p.second++;
							st.emplace(p);
						}else{
							st.emplace(pre,2);
						}
					}else{
						st.emplace(a[i],2);
					}
				}else if(st.top().first < a[i]){
					st.emplace(a[i],1);
				}else{
					if(st.top().second < mid){
						P p = st.top(); st.pop();
						p.second++;
						st.emplace(p);
						continue;
					}
					ll pre = a[i];
					bool emp = false;
					while(st.top().first==pre && st.top().second==mid){
						pre--;
						if(pre == 0) break;
						st.pop();
						if(st.empty()){
							emp = true;
							st.emplace(pre,2);
							break;
						}
					}
					if(pre == 0){
						flag = false;
						break;
					}
					if(emp) continue;
					if(st.top().first == pre){
						P p = st.top(); st.pop();
						p.second++;
						st.emplace(p);
					}else{
						st.emplace(pre,2);
					}
				}
			}
		}
		if(flag) ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
}