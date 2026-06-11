#include<iostream>

using namespace std;

int main()
{
	int n,x;
	cin >> n >> x;
	int m[n];
	for(int i=0; i<n; i++)
		cin >> m[i];

	int max = m[0],total=0;
	for(int i=0; i<n; i++){
		total += m[i];
		if(max > m[i])
			max = m[i];
	}

	int result = n + (x - total) / max;
	cout << result << endl;
}