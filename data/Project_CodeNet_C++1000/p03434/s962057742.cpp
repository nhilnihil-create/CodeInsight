#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<iterator>
#include<iomanip>
#include<cmath>
#include<map>
#include<string.h>
#include<algorithm>
using namespace std;

void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
}

int main()
{
	fast();

	int a[1000],sumeven=0,sumodd=0;
	int n;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		v.push_back(a[i]);
	}
	sort( v.begin(),v.end());
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			sumeven += v[i];
		else
			sumodd += v[i];
	}
	cout << abs(sumeven - sumodd) << endl;

}

