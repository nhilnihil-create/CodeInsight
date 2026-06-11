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


int largest(int a, int b){
	return (a<b)?b:a;
}


int main() {
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> a;
	int number = 0;
	for(int i = 0; i < n; ++i){
		int k = 0;
		cin >> k;
		for(int j = 0; j < k; ++j){
			cin >> number;
			a.push_back(number);
		}
	}
	sort(a.begin(), a.end());
	int cnt = 1;
	int ans = 0;
	for(int i = 0; i < a.size(); ++i){
		if(a[i] == a[i+1]){
			++cnt;
		}
		else{
			if(cnt == n){
				++ans;
			}
			cnt = 1;
		}
	}
	cout << ans << endl;

    return 0;
} 