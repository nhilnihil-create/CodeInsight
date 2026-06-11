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
	string s;
	cin >> s;
	if(s=="AKIHBR") cout << "YES" << endl;
	else if(s=="KIHABR") cout << "YES" << endl;
	else if(s=="AKIHABR") cout << "YES" << endl;
	else if(s=="KIHBAR") cout << "YES" << endl;
	else if(s=="AKIHBAR") cout << "YES" << endl;
	else if(s=="KIHABAR") cout << "YES" << endl;
	else if(s=="AKIHABAR") cout << "YES" << endl;
	else if(s=="KIHBRA") cout << "YES" << endl;
	else if(s=="AKIHBRA") cout << "YES" << endl;
	else if(s=="KIHABRA") cout << "YES" << endl;
	else if(s=="AKIHABRA") cout << "YES" << endl;
	else if(s=="KIHBARA") cout << "YES" << endl;
	else if(s=="AKIHBARA") cout << "YES" << endl;
	else if(s=="KIHABARA") cout << "YES" << endl;
	else if(s=="AKIHABARA") cout << "YES" << endl;
	else if(s=="KIHBR") cout << "YES" << endl;
	else cout << "NO" << endl;
}
