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

char arr[57][57];
int main(){
	Lancer();
	ll n, m, r;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			r = 0;
			if (arr[i][j] == '.')
			{
				if (arr[i][j + 1] == '#')
					r++;
				if (arr[i][j - 1] == '#')
					r++;
				if (arr[i + 1][j] == '#')
					r++;
				if (arr[i - 1][j] == '#')
					r++;
				if (arr[i + 1][j + 1] == '#')
					r++;
				if (arr[i - 1][j - 1] == '#')
					r++;
				if (arr[i - 1][j + 1] == '#')
					r++;
				if (arr[i + 1][j - 1] == '#')
					r++;

				arr[i][j] = char(r + '0');
			}
		}
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)
			cout << arr[i][j];
		cout << endl;
	}
	//cout << endl;
	return 0;
}
