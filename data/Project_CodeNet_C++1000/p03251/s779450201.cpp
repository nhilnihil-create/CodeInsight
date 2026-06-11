#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>//for queue and priority_queue
#include <fstream>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#define endl "\n"
typedef long long ll;
using namespace std;
void Lancer() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
bool isPrime(ll n){
	if (n == 2 || n == 3 || n == 5)
		return true;
	else if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n == 1)
		return false;
	else {
		for (int i = 5; i <= sqrt(n); i += 2){
			if (n%i == 0)
				return false;
		}
		return true;
	}
}

char arr[107][107];
int main(){
	Lancer();
	int n, m, x, y, mn = 105, mx = -105;
	cin >> n >> m >> x >> y;
	vector<int> vec(n + m);
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		mx = max(vec[i], mx);
	}
	for (int i = n; i < m + n; i++){
		cin >> vec[i];
		mn = min(vec[i], mn);
	}
	bool ch = false;
	for (int i = 0; i < n + m; i++){
		if (vec[i] > x &&vec[i] <= y && vec[i]>mx && mn >= vec[i]){
			ch = true;
			break;
		}
	}
	if (ch)cout << "No War";
	else cout << "War";
	cout << endl;
	return 0;
}
