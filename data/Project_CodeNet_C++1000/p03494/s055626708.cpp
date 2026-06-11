#include<iostream>
#include<cmath>
#include<algorithm>
#include<climits>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	ll count = INT_MAX, tmp = 0;
	for(int i=1; i<=n; i++){
		ll x;
		cin >> x;
		while(x%2==0){
			x /= 2;
			tmp++;
		}
		count = min(count, tmp);
		tmp = 0;
	}
	cout << count << endl;
	return 0;
}
