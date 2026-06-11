#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const ll INF=1e18;

int main (){
	int n;
	cin >> n;
	ar<ll,3> a={0,0,0};
	ar<ll,3> buffer;
	ar<ll,3> buffer1;
	for(int i=0; i<n; ++i){
		cin >> buffer[0] >> buffer[1] >> buffer[2];
		buffer1=a;
		a[0]=max(buffer1[1]+buffer[0], buffer1[2]+buffer[0]);
		a[1]=max(buffer1[0]+buffer[1], buffer1[2]+buffer[1]);
		a[2]=max(buffer1[0]+buffer[2], buffer1[1]+buffer[2]);
	}
	cout << max({a[0],a[1],a[2]});
	return 0;
}

