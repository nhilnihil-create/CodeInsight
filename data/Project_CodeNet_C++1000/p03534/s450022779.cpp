#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"
#include "set"

#define lp(n) for (int i = 0; i < n; i++)
#define LP(n,i) for (int i = 0; i < n; i++)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nya_n "(=^･ω･^=)"
typedef long long ll;
using namespace std;

string s;
int cnta, cntb, cntc;

int main() {
	cin >> s;
	cnta = cntb = cntc = 0;
	lp(s.size())
		if (s[i] == 'a')cnta++;
		else if (s[i] == 'b')cntb++;
		else cntc++;
	if (abs(cnta - cntb) <= 1 && abs(cntb - cntc) <= 1 && abs(cntc - cnta) <= 1)
		cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}