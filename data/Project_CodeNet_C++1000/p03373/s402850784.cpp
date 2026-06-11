/*
ID: markusz1
TASK: template
PROG: template
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ul;
typedef priority_queue<int> p_int_max;														// top is max
typedef priority_queue<int, vector<int>, greater<int>> p_int_min; // top is min
typedef priority_queue<ll> p_ll;
typedef priority_queue<double> p_double;
typedef pair<int, int> pr;
typedef map<int, int> m_int;
// ascending order
bool compare_pr_second(pr &a, pr &b) { return a.second > b.second; }

int a, b, c, x, y, sum, temp, smaller, larger;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("template.in","r",stdin);
	//freopen("template.out","w",stdout);

	cin >> a >> b >> c >> x >> y;
	// casework
	smaller = min(x, y);
	larger = max(x, y);

	sum = a * x + b * y;	 // individual pizzas
	temp = 2 * larger * c; // buy all half-and-halfs
	if (temp < sum)
		sum = temp;

	// half-and-halfs, rest individual
	temp = 2 * smaller * c;
	if (larger == x)
		temp += a * (x - y);
	else if (larger == y)
		temp += b * (y - x);
	if (temp < sum)
		sum = temp;

	cout << sum << '\n';
}