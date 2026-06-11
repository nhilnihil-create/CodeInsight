#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<functional>
#include<array>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> array(n);
	long long ans,ans2=0,width;
	for (int i = 0;i < n;i++) cin >> array[i];
	sort(array.begin(), array.end(), greater<int>());
	ans = (array[0] + 1) / 2;
	width = array[0];
	if (n == 2) { cout << array[0] << " " << ans2 << endl; return 0; }
	for (int i = 0; i < n;i++)
	{
		if (abs(array[i] - ans) < width) {
				ans2 = array[i];
				width = abs(array[i] - ans);		
		}
		

	}

	cout << array[0] << " " << ans2 << endl;


	return 0;
}
