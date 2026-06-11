#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
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
 
const int MAXN = 1e6 + 5;
int n = 0, m = 0;
int a[MAXN];
int b[MAXN];



int main() {
	int a = 0, b = 0;
	string s;
	cin >> a >> b;
	cin >> s;
	if(s.length() != a + b + 1){
		cout << "No" << endl;
		return 0;
	}
	if(s[a] != '-'){
		cout << "No" << endl;
		return 0;
	}
	s.erase(s.begin()+a);
	for(int i = 0; i < s.length(); ++i){
		if(s[i] == '-'){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	

    return 0;
} 