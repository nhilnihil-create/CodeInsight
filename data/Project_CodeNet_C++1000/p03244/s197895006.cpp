#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int n; 
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)cin >> a[i];
	vector<int> cnt(200000), cnte(200000);
	for(int  i = 0; i < n; i+= 2)cnt[a[i]]++;
	int oelement = max_element(cnt.begin(), cnt.end()) - cnt.begin(), ocnt = *max_element(cnt.begin(), cnt.end());
	*max_element(cnt.begin(), cnt.end()) = 0;

	for(int i = 1; i < n; i += 2) cnte[a[i]]++;
	auto itr = max_element(cnte.begin(), cnte.end());
	int eelement = itr - cnte.begin(), ecnt = *itr;
	*itr = 0;
	/*
	for(int i = 0; i < n; i++)cout << cnt[i] << " ";
	cout << endl;
	*/

	if(eelement == oelement) {
		int on = *max_element(cnt.begin(), cnt.end());
		int en = *max_element(cnte.begin(), cnte.end());
		cout << min(n - (ecnt + on), n - (ocnt + en)) << endl;
	}else {
		cout << n - (ecnt + ocnt) << endl;
	}
}