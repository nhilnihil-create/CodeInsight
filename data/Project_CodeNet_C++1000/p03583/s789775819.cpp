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
const ll INF = 1000000000000000000;

int main()
{
	ll N;
	cin >> N;
	for (int i = 1; i <= 3500; i++) {
		for (int j = 1; j <= 3500; j++) {
			if (4 * i * j - N * i - N * j != 0) {
				if ((N * i * j) % (4ll * i * j - N * i - N * j) == 0) {
					if ((N * i * j) / (4 * i * j - N * i - N * j) > 0) {
						cout << i << " " << j << " " << (N * i * j) / (4 * i * j - N * i - N * j) << endl;
						return 0;
					}
				}
			}
		}
	}
}
