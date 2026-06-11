#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int a[100000];
int main(){
	int N,i;
	cin >> N;
	for (i = 0;i<N;i++)
	{
		cin >> a[i];
	}
	map<int,int> mp;
	for (i = 0; i < N; i++) {
		mp[a[i]]++;
	}
	int x,n,ans = 0;
	for (auto p:mp) {
		x = p.first;
		n = p.second;
		if (n < x) {
			ans+=n;
		}
		else ans +=n-x;
	}
	cout << ans << endl;


	


}