#include<iostream> 
#include<stdio.h>
#include<string>
#include<iomanip> 
#include<vector> 
#include<map> 
#include<set> 
#include<algorithm> 
#include<numeric> 
#include<limits> 
#include<bitset> 
#include<functional> 
#include<type_traits> 
#include<queue> 
#include<stack> 
#include<array> 
#include<random> 
#include<utility> 
#include<cstdlib> 
#include<ctime>
//#define _LIBCPP_DEBUG 0
//#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define all(a) (a).begin(),(a),end()
#define rep(i,n) for (ll i = 0; i < (n); ++i)	
//setprecision(16)

void outi(int x) { cout << x << endl; }
void outl(ll x) { cout << x << endl; }
void outs(string x) { cout << x << endl; }
ll max(ll a, ll b) {
	ll max;
	if (a > b) max = a;
	else max = b;
	return max;
}
ll min(ll a, ll b) {
	ll min;
	if (a < b) min = a;
	else min = b;
	return min;
}
//---------------------------------------------------------------

int main() {
	string s;
	cin >> s;
	string mae;
	mae.push_back(s[0]);
	mae.push_back(s[1]);
	string usiro;
	usiro.push_back(s[2]);
	usiro.push_back(s[3]);

	int m = stoi(mae);
	int u = stoi(usiro);

	
	if (0 < u && u <= 12) {
		if (0 < m && m <= 12) {
			outs("AMBIGUOUS");
		}
		else
		{
			outs("YYMM");
		}
	}
	else {
		if(0 < m && m <= 12)outs("MMYY");
		else outs("NA");
	}
}