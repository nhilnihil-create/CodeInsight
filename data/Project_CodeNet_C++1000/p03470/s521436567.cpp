#include <iostream>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<fstream>
#include<queue>
#include<set>
using namespace std;
void ll(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
}
int main()
{
	ll();

	int n;
	int arr[1000];
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		s.insert(arr[i]);
	}
	cout << s.size() << endl;
}