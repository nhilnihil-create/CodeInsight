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
	ll n;
	bool ok = true;
	cin >> n;
	vector<string> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	for (int i = 0; i < n; i++){
		bool ch = true;
		string a=vec[i], b;
		if (i > 0){
			b = vec[i - 1];
			if (b[b.length() - 1] != a[0]) ch = false;
		}
		for (int j = i - 1; j >= 0; j--){
			if (vec[i] == vec[j]){
				ch = false;
				break;
			}
		}
		if (!ch){
			ok = false;
			break;
		}
	}
	if (ok) cout << "Yes";
	else cout << "No";
	cout << endl;
	return 0;
}
