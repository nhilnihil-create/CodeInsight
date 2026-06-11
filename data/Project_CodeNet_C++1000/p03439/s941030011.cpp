#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const int MOD = 998244353;
const ll INF = 1000000000000000000;

string S[100010];
int main()
{
	int N;
	cin >> N;
	cout << 0 << endl;
	cin >> S[0];
	int ng = 0;
	int ok = N;
	while (abs(ng - ok) > 1) {
		int mid = (ng + ok) / 2;
		cout << mid << endl;
		cin >> S[mid];
		if (S[mid] == "Vacant") return 0;
		if ((ng + mid) % 2 == 0) {
			if (S[ng] == S[mid]) ng = mid;
			else ok = mid;	
		}
		else {
			if (S[ng] == S[mid]) ok = mid;
			else ng = mid;
		}
	}
}