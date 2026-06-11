
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<deque>
#include<list>


using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
const int BIG_INT = 1000000000;



int main() {
	int n;
	cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	bool canConsist;
	stack<int> procedure;
	for (int i = 0; i < n;i++) {
		canConsist = false;
		for (int j = n-1-i; j >=0; j--) {
			
			if (b[j] == j + 1) {
				
				canConsist = true;

				vector<int> tmp(n - i - 1);
				for (int k = 0;k < n - i;k++) {
					if (k < j) {
						tmp[k] = b[k];
						
					}
					if(k > j) {
						tmp[k-1] = b[k];
					}
					
				}

				b = tmp;
				procedure.push(j+1);
				break;
			}

		}
		if (!canConsist) {
			break;
		}
		//cout << i << endl;
	}

	if (canConsist) {
		while (!procedure.empty()) {
			cout << procedure.top() << endl;
			procedure.pop();
		}
	}
	else
	{
		cout << -1 << endl;
	}
	
}

