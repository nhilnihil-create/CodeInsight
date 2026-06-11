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
	string s;
	cin >> s;
	int n = s.size();
	bool one = false, two = false;
	int a = 10*(s[0] - '0') + (s[1]-'0');
	int b = 10*(s[2] - '0') + (s[3]-'0');
	if(1 <= a && a <= 12){
		one = true;
	}
	if(1 <= b && b <= 12){
		two = true;
	}
	if(one && two){
		cout << "AMBIGUOUS" << endl;
	}
	else if(one) {
		cout << "MMYY" << endl;
	} else if(two){
		cout <<"YYMM" << endl;
	} else {
		cout << "NA" << endl;
	}
}
