#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	vector <int> vec(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vec.at(i);
	}
	int A = 0, B = 0;
	 sort (vec.begin(), vec.end());
	 reverse(vec.begin(), vec.end());
	 for (int i = 0; i < N; i++)
	 {
		 if (i == 0 || (i % 2) == 0)
			 A += vec.at(i);
		 else if (i == 1 || (i % 2) == 1)
		 {
			 B += vec.at(i);
		 }
	 }
	 cout << A - B << endl;
}
