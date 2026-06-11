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
#define LANCER_SHARK { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
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
	LANCER_SHARK;
	ll res = 0, t = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++){
		if (str[i] == 'A' || str[i] == 'C' || str[i] == 'G' || str[i] == 'T')
			t++;
		else {
			res = max(res, t);
			t = 0;
		}
	}
	res = max(res, t);
	cout << res;
	cout << endl;
	return 0;
}
