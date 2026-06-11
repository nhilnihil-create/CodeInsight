#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void test(vector<int> array)
{
	for (int i = 0; i < array.size(); i++)
	{
		cout << array[i];
	}

}




int main()
{
	int N;
	cin >> N;

	vector<int> a(N);

	int sum = 0;
	for(int i=0; i<N; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	sort(a.begin(), a.end(), greater<int>());

	//test(a);

	int AlicePoint = 0;
	for (int i = 0 ; i < N; i += 2)
	{
		AlicePoint += a[i];
	}

	cout << 2 * AlicePoint - sum;
}

