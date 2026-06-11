#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, d, x;
	cin >> n ;
	cin >> d >> x;
	/*vector<int> a;
	int i, count = x;
	for(i=0; i<n; i++){
		int p;
		cin>>p;
		a.push_back(p);
	}*/
	int i, p, count = x;
	for(i=0; i<n; i++){
		cin >> p;
		count++;
		for(int j=1; ; j++){
			if((j*p)+1<=d) count++;
			else break;
		}
	}
	cout << count << endl;
	return 0;
}
