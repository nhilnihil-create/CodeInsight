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
	string s1, s2;
	cin >> s1 >> s2;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	if (s2[s2.length() - 1] > s1[0])
		cout << "Yes";
	else if (s1.length() < s2.length()){
		for (int i = 0; i < s1.length(); i++){
			if (s1[i] != s2[i]){
				cout << "No";
				return 0;
			}
		}
		cout << "Yes";
	}
	else cout << "No";
	cout << endl;
	return 0;
}
