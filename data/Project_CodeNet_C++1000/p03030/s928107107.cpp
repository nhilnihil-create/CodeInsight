#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
 
//Write From this Line

//const ll mod = 1e9+7;
//const ll mod = 998244353;
int main()
{
	int n;
	cin >> n;
	vector<tuple<string,int,int>> a(n);
	rep(i,n){
		string s; int p;
		cin >> s >> p;
		p *= -1;
		a[i] = make_tuple(s,p,i+1);
	}
	SORT(a);
	rep(i,n){
		cout << get<2>(a[i]) << endl;
	}
}
