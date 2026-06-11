#include <bits/stdc++.h>
using namespace std;
#define whole(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define ins insert
#define _(a) #a << " : " << (a)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> x;
#define v first
#define id second
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9;
int n, k, m;
int cnt[maxn];
string s;
void input ()
{
	cin >> s;
	n = s.length ();
	s.ins (0, " ");
	for (int i = 1; i <= n; ++i)
		cnt[i] = cnt[i - 1] ^ (1 << (s[i] - 'a'));
}
map <int, int> l;
int f[maxn];
void solve ()
{
	l.ins (mp (0, 0));
	f[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		f[i] = n;
		auto it = l.find (cnt[i]);
		if (it != l.end ()) f[i] = min (f[i], f[it -> id] + 1);
		for (int j = 0; j < 26; ++j)
		{
			int x = (1 << j) ^ cnt[i];
			// cerr << x;
			auto it2 = l.find (x);
			if (it2 != l.end ())
				f[i] = min (f[i], f[it2 -> id] + 1);
		}
		it = l.find (cnt[i]);
		if (it == l.end ()) l.ins (mp (cnt[i], i));
		else if (f[it -> id] > f[i]) it -> id = i;
		// cerr << i << ' ';
	}
	cout << f[n];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	input ();
	solve ();
}
