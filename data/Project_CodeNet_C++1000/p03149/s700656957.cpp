#include <bits/stdc++.h>
using namespace std;
int main() {
	int A[4],p=1;
	vector<int> B(4, 0);
	for (size_t i = 0; i < 4; i++)
	{
		cin >> A[i];
		if (A[i]==1)
		{
			B.at(0)++;
		}
		else if (A[i]==9)
		{
			B.at(1)++;
		}else if(A[i] == 7)
		{
			B.at(2)++;
		}
		else if (A[i] == 4)
		{
			B.at(3)++;
		}
	}
	for (size_t i = 0; i < 4; i++)
	{
		p *= B.at(i);
	}
	if (p==1)
	{
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}