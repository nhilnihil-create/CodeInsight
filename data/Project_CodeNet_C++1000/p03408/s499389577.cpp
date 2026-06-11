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
	ll n, m, ans = 0;
	cin >> n;
	vector<string>blue(n);
	for (int i = 0; i < n; i++)
		cin >> blue[i];
	cin >> m;

	vector<string>red(m);
	for (int i = 0; i < m; i++)
		cin >> red[i];

	for (int i = 0; i < n; i++){
		bool ch = true;
		ll t = 0;
		for (int j = 0; j < m; j++){
			if (blue[i] == red[j])t--;
			
		}
		for (int j = 0; j < n; j++){
			if (blue[i] == blue[j])
				t++;
		}
		ans = max(t, ans);
	}
	cout << ans;
	cout << endl;
	return 0;
}
