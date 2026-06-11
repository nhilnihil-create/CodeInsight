#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int n,t,a;
	cin >> n >> t >> a;
	int H[n];
	for(int i=1; i<=n; i++)
		cin >> H[i];

	double tem[n], tmp;
	for(int i=1; i<=n; i++)
		tem[i] = t - H[i] * 0.006;
	
	int index=1;
	double min = abs(tem[1] - a);

	//cout << min << endl;

	for(int i=2; i<=n; i++){
		tmp = abs(tem[i] - a);
		if(min > tmp){
			min = tmp;
			index = i;
		}
	}
	cout << index << endl;




}
