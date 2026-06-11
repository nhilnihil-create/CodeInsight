#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<set>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)

using namespace std;
typedef pair<int, int> pii;

typedef long long int ll;

template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
	return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T& t, const V& v) { t = v; }
template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T& t, const V& v) {
	for (auto& e : t) fill_v(e, v);
}


#define ARRAY_MAX 5005
const ll INF = 1e9 + 7;

struct circle {

	double x;
	double y;
	double r;
};

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

const ll MOD = 1e9 + 7;

int main() {

	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;

	vector<char> c(q), t(q);
	for (int i = 0; i < q; i++)
	{
		cin >> c[i] >> t[i];
	}

	int ng = -1;
	int ok = n;

	while (ok - ng > 1)
	{
		int mid = (ok + ng) / 2;//ここまでは左に落ちる

		int idx = mid;

		bool flag = false;

		for (int i = 0; i < q; i++)
		{
			if (s[idx] == c[i])
			{
				if (t[i] == 'L')
				{
					idx--;
				}
				else
				{
					idx++;
				}
			}
			if (idx < 0)
			{
				flag = true;
				break;
			}
			if (idx >= n)
			{
				
				flag = false;
				break;
			}
		}

		if (flag)
		{
			ng = mid;
		}
		else
		{
			ok = mid;
		}
	}

	int ng2 = -1;
	int ok2 = n;

	while (ok2 - ng2 > 1)
	{
		int mid = (ok2 + ng2) / 2;//ここまでは左に落ちる

		int idx = mid;

		bool flag = false;

		
		for (int i = 0; i < q; i++)
		{
			if (s[idx] == c[i])
			{
				if (t[i] == 'L')
				{
					idx--;
				}
				else
				{
					idx++;
				}
			}
			if (idx < 0)
			{
				flag = false;
				break;
			}
			if (idx >= n)
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			ok2 = mid;
		}
		else
		{
			ng2 = mid;
		}
	}

	cout << ok2 - ok << endl;


	return 0;
}