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
	ll a, b, k, l;
	cin >> a >> b >> k;
	l = max(a,b)-k;
	ll i;
	for ( i = min(a, b); i <= max(a, b); i++){
		if (k--) cout << i<<endl;
		else break;
	}
	for (int j = max(l+1,i); j <= max(a, b); j++){
		if (l--)cout << j<<endl;
		else break;
	}
	//cout << endl;
	return 0;
}
