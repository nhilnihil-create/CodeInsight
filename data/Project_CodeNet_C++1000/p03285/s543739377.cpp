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

//int frq[123];
int main(){
	Lancer();
	ll n;
	cin >> n;
	if (n % 4 == 0 || n % 7 == 0)
		cout << "Yes";
	else {
		bool ch = false, ok = false;
		int i = n;
		while (n>4)
		{
			n -= 4;
			if (n% 7 == 0){
				ch = true;
				break;
			}
		}
		while (i>7)
		{
			i -= 7;
			if (i % 4 == 0){
				ok = true;
				break;
			}
		}
		if (ch || ok) cout << "Yes";
		else cout << "No";
	}
	cout << endl;
	return 0;
}
