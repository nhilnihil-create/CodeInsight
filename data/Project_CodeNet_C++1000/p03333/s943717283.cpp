#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#include <tuple>
#include <functional>
#include <cfloat>
#include <map>

//LLONG_MAX
#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define LOWER_BOUND(v,a) (lower_bound((v).begin(), (v).end(), (a)))
#define UPPER_BOUND(v,a) (upper_bound((v).begin(), (v).end(), (a)))
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
using namespace std;

int N;

using P = pair<int, int>;
bool flg1[100001];
priority_queue<P, vector<P>, greater<P>> q1_r;
priority_queue<P> q1_l;

bool flg2[100001];
priority_queue<P, vector<P>, greater<P>> q2_r;
priority_queue<P> q2_l;

int Calc(priority_queue<P, vector<P>, greater<P>>& q_r, priority_queue<P>& q_l, bool flg[100001], bool is_r)
{
	int sum = 0;

	int cur = 0;

	if (is_r)
	{
		P p = q_r.top();
		q_r.pop();
		sum += abs(cur - p.first);
		cur = p.first;
		flg[p.second] = true;
	}

	while (true)
	{
		while (true)
		{
			if (q_l.size() <= 0)
			{
				sum += abs(cur);
				return sum;
			}

			P p = q_l.top();
			if (flg[p.second])
			{
				q_l.pop();
				continue;
			}
			if (p.first <= cur)
			{
				sum += abs(cur);
				return sum;
			}
			q_l.pop();
			sum += abs(cur - p.first);
			cur = p.first;
			flg[p.second] = true;
			break;
		}

		while (true)
		{
			if (q_r.size() <= 0)
			{
				sum += abs(cur);
				return sum;
			}

			P p = q_r.top();
			if (flg[p.second])
			{
				q_r.pop();
				continue;
			}
			if (p.first >= cur)
			{
				sum += abs(cur);
				return sum;
			}
			q_r.pop();
			sum += abs(cur - p.first);
			cur = p.first;
			flg[p.second] = true;
			break;
		}
	}

	sum += abs(cur);
	return sum;
}

signed main()
{
	cin >> N;
	REP(i, N)
	{
		int l, r;
		cin >> l >> r;
		q1_r.push(P(r, i));
		q1_l.push(P(l, i));
		q2_r.push(P(r, i));
		q2_l.push(P(l, i));
	}

	int ans = 0;
	if (q1_r.top().first < 0)
	{
		int calc = Calc(q1_r, q1_l, flg1, true);
		ans = MAX(ans, calc);
	}
	if (q2_l.top().first > 0)
	{
		int calc = Calc(q2_r, q2_l, flg2, false);
		ans = MAX(ans, calc);
	}

	cout << ans << endl;
}





