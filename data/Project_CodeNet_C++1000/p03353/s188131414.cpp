#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include<algorithm>
#include<sstream>
#include<iomanip>


using namespace std;



int main() {
	string s;
	int k;
	cin >> s >> k;
	int n = s.length();
	
	set<string> dic;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j+i <= n && j <=k; j++) {
			
			string sb = s.substr(i, j );
			
			//cout << sb << endl;
			dic.insert(sb);
		}
	}

	auto p = dic.begin();
	for (int i = 1; i < k; i++) {
		p++;
	}

	cout << *p << endl;
	
}