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

int frq[123];
int main(){
	Lancer();
	ll d, n;
	cin >> d >> n;
	if (n < 100){
		if (d == 0)
			cout << n;
		else if (d == 1)
			cout << n * 100;
		else
			cout << n * 10000;
	}
	else {
		if (d == 0)
			cout << n+1;
		else if (d == 1)
			cout << (n+1) * 100;
		else
			cout << (n+1) * 10000;

	}
	cout << endl;
	return 0;
}
