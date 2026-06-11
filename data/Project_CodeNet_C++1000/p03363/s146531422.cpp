#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<long long> a(n+1);
	for(int i=1;i<n+1;i++){
		cin >> a[i];
		//累積和をとる
		a[i]+=a[i-1];
	}

	long long ans=0;
	map<long long,int> m;

	//各値の数を数えながらnC2を求めていく
	for(int i=0;i<n+1;i++){
		ans+=m[a[i]];
		m[a[i]]++;
	}

	cout << ans << endl;
}