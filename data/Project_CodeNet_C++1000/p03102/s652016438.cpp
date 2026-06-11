#include<iostream>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	int n, m, c;
	cin >> n >> m >> c;
	int b[m], i;
	for(i=0; i<m; i++){
		cin >> b[i];
	}
	int sum=0, count = 0;
	for(i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int x;
			cin >> x;
			sum += x*b[j];
		}
		if(sum+c>0) count++;
		sum = 0;
	}
	cout << count << endl;
	return 0;
}
