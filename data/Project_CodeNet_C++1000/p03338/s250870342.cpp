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
	ll n, t, res = -1;
	string str;
	cin >> n>>str;
	//aabbca
	for (int i = 0; i < n; i++){
		t = 0;
		for (int j = 0; j <= i; j++){
			bool ch = true;
			for (int k = j-1; k >=0; k--){
				if (str[j] == str[k]){
					ch = false;
					break;
				}
			}
			if (ch){
				for (int k = i + 1; k < n; k++){
					if (str[j] == str[k]){
						t++;
						break;
					}
				}
			}
		}
		res = max(t, res);
	}
	cout << res;
	cout << endl;
	return 0;
}
