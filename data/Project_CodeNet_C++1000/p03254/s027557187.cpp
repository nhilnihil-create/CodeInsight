#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int n,x,i,count = 0;
	cin >> n >> x;
	vector<int> p(n);
	for(i = 0; i < n; i++)
		cin >> p[i];
	sort(p.begin(),p.end());

	for(i = 0; i < n; i++){
		if(i == n-1 && x - p[i] != 0)
			break;
			
		if(x - p[i] >= 0){
			x -= p[i];
			count++;
		}
	}
	cout << count << endl;
}
