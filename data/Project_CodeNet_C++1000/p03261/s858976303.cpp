#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
#include <string>
#include <iterator>
#include <vector>
 
using namespace std;

typedef long long ll;
typedef long double ld;
#define L(ID) ((ID*2)+1)
#define R(ID) ((ID*2)+2)
#define M(L,R) ((L+R)/2)
#define forr(start,end) for(int i = start; i < end; i++)
#define gap ' '
 
const int MAXN = 2 * 1e5 + 5;
string s;

int largest(int a, int b){
	return (a<b)?b:a;
}


int main() {
	int n = 0;
	cin >> n;
	vector<string> a;
	string s;
	for(int i = 0; i < n; ++i){
		cin >> s;
		a.push_back(s);
	}
	for(int i = 1; i < n; ++i){
		string k = a[i];
		string j = a[i-1];
		if(k[0] != j[j.length()-1]){
			cout << "No" << endl;
			return 0;
		}
	}
	set<string> a1;
	for(int i = 0; i < n; ++i){
		a1.insert(a[i]);
	}
	if(a1.size() != n){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;



    return 0;
}