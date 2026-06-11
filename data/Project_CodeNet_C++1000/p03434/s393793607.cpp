#include<iostream>
#include<algorithm>
#include<vector>
#define pb push_back
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	int i, n;
	cin >> n;
	vector<int> a;
	for(i=0; i<n; i++){
		int x;
		cin >> x;
		a.pb(x);
	}
	sort(a.begin(), a.end(), greater<int>());
	int alice = 0, bob = 0;
	for(i=0; i<n; i++){
		if(i%2==0) alice += a[i];
		else bob += a[i];
	}
	cout << alice-bob << endl;
	return 0;
}
