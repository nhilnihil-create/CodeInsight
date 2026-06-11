#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#define PI 3.14159265359
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pai;
typedef pair<ll, ll> pal;
const int MOD = 1e9+7;
const ll LLINF = 1e18;


int main(){
	int n;
	cin >> n;

	vector<int> c(n), s(n), f(n);
	for (int i = 0; i < n-1; i++){
		cin >> c[i] >> s[i] >> f[i];
	}

	for (int i = 0; i < n; i++){
		int temp = 0;
		for (int now = i; now < n-1; now++){
			while (1){
				if (temp < s[now]){
					temp = s[now];
				}
				if (temp % f[now] == 0){
					break;
				}
				temp++;
			}
			temp += c[now];
		}
		cout << temp << endl;
	}
	return 0;
}