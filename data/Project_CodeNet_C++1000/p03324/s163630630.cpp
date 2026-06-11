#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9 * 2;

int main() {
	int d, n;
	cin >> d >> n;
	int cok = 0;
	for(int i = 1; i < INF; i++){
		int num = i;
		int count = 0;
		while(num % 100 == 0){
			num /= 100;
			count++;
		}
		if(count == d) cok++;
		if(cok == n){
			cout << i << endl;
			return 0;
		}
	}
}
