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
 
//char arr[107][107];
int main(){
	Lancer();
	double n, t, a,h, ind=1,res = 1000000000000000000,d;
	cin >> n >> t >> a;
	for (int i = 0; i < n; i++){
		cin >> h;
		d = t- (h*0.006);
		d = abs(d-a);
		//cout << d << endl;
		if (d < res){
			res = d;
			ind = i+1;
		}
	}
	cout << ind;
	cout << endl;
	return 0;
}