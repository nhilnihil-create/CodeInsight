#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int n; 
  	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
	cin >> arr[i];
 
	int count=0;
 
	for(int i = 0; i < n;) {
		int j = i;
		while(arr[j] == arr[i] && j < n) {
			j++;
		}
		count += (j - i) / 2;
		i = j;
	}
	cout<<count;
  return 0;
}