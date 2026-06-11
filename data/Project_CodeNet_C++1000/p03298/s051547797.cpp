#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592
#define PI acos(-1.0);

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;



int main(){
	int N; cin >> N;
	string s; cin >> s;
	string t1 = s.substr(0,N);
	reverse(s.begin(),s.end());
	string t2 = s.substr(0,N);
	vector<pair<string,string>> v1; 
	rep(i,1<<N){
		string a = "";
		string b = "";
		rep(j,N){
			if(i>>j&1) a += t1[j];
			else b += t1[j];

		}
		reverse(b.begin(),b.end());
		v1.emplace_back(a,b);
	}
	vector<pair<string,string>> v2;
	rep(i,1<<N){
		string a = "";
		string b = "";
		rep(j,N){
			if(i>>j&1) a += t2[j];
			else b += t2[j];
		}
		reverse(b.begin(),b.end());
		v2.emplace_back(a,b);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	ll ans = 0;
	rep(i,1<<N){
		ans += upper_bound(v2.begin(),v2.end(),v1[i])-lower_bound(v2.begin(),v2.end(),v1[i]);
	}
	cout << ans << endl;
}

