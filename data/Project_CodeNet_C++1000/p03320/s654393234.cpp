#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include <fstream>
#include <time.h>
#include <iterator>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
//#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

const int MOD = (ll)1000000000 + 7;
const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;
typedef pair<int, int>P;

double calc(string s) {
	int sm = 0;
	REP(i, s.size()) {
		sm += s[i] - '0';
	}
	return stod(s) / sm;
}
string LLtoS(ll x) {
	string res;
	while (x > 0) {
		res += '0' + x % 10;
		x /= 10;
	}
	VREVERSE(res);
	return res;
}

string func(string n) {
	int N = n.size();
	int s = N - 1;//s+1~N-1まで全部9
	for (int i = N - 1; i >= 0; i--) {
		if (n[i] == '9') {
			s--;
		}
		else break;
	}
	//999...9のとき
	if (s == -1) {
		string str = "1";
		REP(i, N) {
			str += '0';
		}
		return func(str);
	}
	if (N == 1) {
		if (n[0] != '9');
		n[0]++;
		return n;
	}
	//X99...9のとき
	else if (s == 0) {
		ll pos = (ll)stod(n);
		pos++;
		string str=LLtoS(pos);
		//print(str);
		/*str+=n[0];
		str[0] += 1;
		FOR(i, 1, N) {
			str += "0";
		}*/
		//print(str)
		return func(str);
	}
	
	map<double, string>mp;
	double mn = (double)INF;
	//i桁目以降を全部9にする
	for (int i = s+1; i > 0; i--) {
		if (i >= N)continue;
		string str = n;
		for (int j = N - 1; j >= i; j--) {
			str[j] = '9';
		}
		while (str[i - 1] <= '9') {
			if (str != n) {
				double res = calc(str);
				mn = min(mn, res);
				mp[res] = str;
			}
			
			if(str[i-1]<'9')str[i - 1]++;
			//print(str);
			double res = calc(str);
			//pe(str)print(res);
			mn = min(mn, res);
			mp[res] = str;
			
			if (str[i - 1] == '9')break;
			
		}
	}
	//print(mn);
	return mp[mn];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string res = "0";
	//print(func(res));
	int K; cin >> K;
	REP(i, K) {
		res = func(res);
		print(res);
	}
}