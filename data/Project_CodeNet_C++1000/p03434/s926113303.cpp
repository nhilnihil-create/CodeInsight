#include <bits/stdc++.h>

using namespace std;
#define NIL -1
#define ll long long
#define MAX 100
#define pb push_back

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n);
	ll s1=0, s2=0;
	for(int i=0; i<n; i++) {
		if(i%2) s2+=arr[i];
		else s1+=arr[i];
	}
	//cout << s1 <<  " " << s2 << endl;
	cout << abs(s1-s2) << endl;
	return 0;
}
