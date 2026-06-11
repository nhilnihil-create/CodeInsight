#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[100005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint lb = 2, ub = 2;
	for(int i = n; i >= 1; i--){
		lb = (lb+a[i]-1)/a[i]*a[i];
		ub = ub/a[i]*a[i];
		if(lb > ub){
			cout << -1 << endl;
			return 0;
		}
		ub += a[i]-1;
	}
	cout <<lb << " " << ub << endl;
	
	return 0;
}