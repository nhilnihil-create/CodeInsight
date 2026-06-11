#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, k, x, a[30]={0}, cnt=0;
	cin>>n>>m;
	for(int i =0;i<n;++i){
		cin>>k;
		while(k--){
			cin>>x;
			a[x-1]++;
		}
	}
	for(int i=0;i<m;i++){
		if(a[i]==n)cnt++;
	}
	cout << cnt << endl;
}