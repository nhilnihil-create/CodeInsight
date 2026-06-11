/* 
	Author: ankrypt
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int
#define ff first
#define ss second
#define all(x) x.begin(), x.end() 
#define ub upper_bound
#define lb lower_bound
#define MAX_INT 15
#define PI 3.141592653589793
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi(a, b, c, d) for(int a = b; a < c; a += d)
#define fl(a, b, c, d) for(ll a = b; a < c; a += d)
#define fei(a, b, c, d) for(int a = b; a <= c; a += d)
#define fel(a, b, c, d) for(ll a = b; a <= c; a += d)
#define quit exit(0)
#define mem(x, a) memset(x, a, sizeof x)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pcl pair<char, ll>
#define psl pair<string, ll>


ll N, M, A, B, C;
ll arr[MAX_INT], arr1[MAX_INT], data[MAX_INT];
vector<ll> V;
unordered_map<ll, ll> mp;
set<ll> s;
string S = "";
ll cases;
char alpha[4] = {'A', 'G', 'C', 'T'};

int main() {
	go;
    cin >> S;
    ll k = 0;
    ll maxAns = 0;
    fi(i, 0, S.size(), 1) {
    	// trace1(i);
    	fi(j, 0, 4, 1) {
    		// trace1(j);
    		if(S[i] == alpha[j]) {
    			k = i;
    			ll cnt = 0;
    			while(k < S.size()) {
    				// trace1(k);
    				int flag = 0;
    				fi(l, 0, 4, 1) {
    					if(S[k] == alpha[l]) {
    						flag = 1;
    						break;
    					}
    				}
    				if(!flag) {
    					break;
    				}
    				else {
    					cnt++;
    					maxAns = max(maxAns, cnt);
    				}
    				k++;
    			}
    			i += cnt - 1;
    		}
    	}
    }
    cout << maxAns << "\n";
	return 0;
}
/*
	Powered by Buggy Plugin
*/


