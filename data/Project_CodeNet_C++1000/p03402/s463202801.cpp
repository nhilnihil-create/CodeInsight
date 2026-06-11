#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
	int a, b;
	cin >> a >> b;

    cout << 100 << " " << 100 << "\n";
	
	int cnt = b-1;
	rep(i, 50) {
		rep(j, 100) {
			if(i%2 == 0 && j%2 == 0 && cnt > 0) {
                cout << '#';
                cnt--;
            }
			else {
                cout << '.';
            }
		}
		cout << "\n";
	}

	cnt = a-1;
	rep(i, 50) {
		rep(j, 100) {
			if(i%2 == 1 && j%2 == 0 && cnt > 0) {
                cout << '.';
                cnt--;
            }
			else {
                cout << '#';
            } 
		}
		cout << "\n";
	}

    return 0;
}