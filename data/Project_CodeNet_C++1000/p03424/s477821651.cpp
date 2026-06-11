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

//char arr[57][57];
int main(){
	Lancer();
	ll n, p = 0, w = 0, g = 0, y = 0;
	char c;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> c;
		if (c == 'P')
			p++;
		else if (c == 'W')
			w++;
		else if (c == 'G')
			g++;
		else
			y++;
	}
	if (p && w && g && y)
		cout << "Four";
	else
		cout << "Three";
	cout << endl;
	return 0;
}
