#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int count = 1;
	map<int, int> a;
	a[n]++;
	while(a[n]!=2){
		count++;
		if(n%2) n = 3*n + 1;
		else n = n/2;
		a[n]++;
	}
	cout << count << endl;
	return 0;
}
