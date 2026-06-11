#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <complex>
#include <iomanip>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <cstring>

#define ll long long
#define ld long double
#define HS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f3f3f3f3f
#define point complex <double> 
#define pi acos(-1)
#define mod 1000000007


using namespace std;


double dot(point a, point b)
{
	return (conj(a) * b).real();
}
double cross(point a, point b)
{
	return (conj(a) * b).imag();
}
//double hypotness = hypot(3, 4);

int cum[100005];


int main() {
	HS
	int n, k;
	cin >> n >> k;
	int mini = 1e9;
	int arr[100005];
	int pos;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	ll ans = 0;
	for (int i = 1; i < n; i++)
	{
		ans++;
		i += k - 2;
	}

	cout << ans << endl;
	/*ll ans = 0;
	for (int i = pos; i < n; i++)
	{
		ans++;
		i += k - 2;
	}

	for (int i = pos; i > 1; i--)
	{
		ans++;
		i -= k - 2;
	}
	cout << ans << endl;
	*/
	return 0;
}