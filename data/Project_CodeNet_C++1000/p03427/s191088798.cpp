#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using P = pair<int,int>;
//Write From this Line

int main()
{
	string n;
	cin >> n;
	if(n.size() == 1){
		cout << stoi(n) << endl;
		return 0;
	}
	bool wee = true;
	For(i,1,n.size()){
		if(n[i] != '9'){
			wee = false;
			break;
		}
	}
	int ans = n.size() * 9 - 9;
	string b = "";
	b +=  n[0];
	int a = stoi(b);
	if(wee){
		cout << ans + a << endl;
		return 0;
	}
	cout << ans + a - 1 << endl;
}
