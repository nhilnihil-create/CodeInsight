#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;

struct edge { int to, cost; };

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> P;
 
const int INF = 1e9;
//const ll INF = 1e18;
const double EPS = 1e-10;
const int MOD = 1e9+7;
const double PI = acos(-1.0);

int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	cout << (a == b && b == c ? "Yes" : "No") << endl;
	return 0;	
}