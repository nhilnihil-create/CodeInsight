#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
int main()
{
	vector<int> a(3);
	int sum=0;
	rep(i,3) cin >> a[i];
	sort(a.begin(), a.end());
	rep(i,2){
		sum += (a[i+1] - a[i]);
	}
	cout << sum <<endl;
	return 0;
}