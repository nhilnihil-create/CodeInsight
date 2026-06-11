#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<climits>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<iomanip>
using namespace std;

#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define rep2(i,j,n) for(int i=(j);i<=(n);i++)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(),i.rend()
#define INF 1e9

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pi;
typedef long long i64;
typedef vector<long long int> vll;

int main() {
	int a, b;
	cin >> a >> b;
	if (a + b == 15) cout << "+" << endl;
	else if (a*b == 15) cout << "*" << endl;
	else cout << "x" << endl;
}
