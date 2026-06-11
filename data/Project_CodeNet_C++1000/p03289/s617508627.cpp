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
	string str;
	cin >> str;
	ll c = 0,ch=0,l=str.size(),ind;
	for (int i = 0; i < l; i++){
		if (str[i] == 'C'){
			c++;
			ind = i;
		}
		else if (str[i] >= 'a' &&str[i] <= 'z')
			ch++;
	}
	if (str[0] == 'A'  && c==1 && ch==l-2 && ind>=2  && ind <=l-2) cout << "AC";
	else cout << "WA";
	cout << endl;
	return 0;
}
