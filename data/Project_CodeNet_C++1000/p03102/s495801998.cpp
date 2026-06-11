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
void LANCER_SHARK() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
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

int frq[50];
int main(){
	LANCER_SHARK();
	ll n, m, c, a,sum, res = 0;
	cin >> n >> m >> c;
	vector<int>vec(m);
	for (int j = 0; j < m; j++)
		cin >> vec[j];

	for (int i = 0; i < n; i++){
		sum = 0;
		for (int j = 0; j < m; j++){
			cin >> a;
			sum += (a*vec[j]);
		}
		sum += c;
		res = sum > 0 ? ++res : res;
	}
	cout << res;
	cout << endl;
	return 0;
}
