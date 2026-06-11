#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ll n,h,w;
	cin >> n >> h >> w;
	ll y,x;
	ll count = 0;
	for(int i = 0; i < n; i++){
		cin >> y >> x;
		if(y >= h && x >= w)count++;
	}
	cout << count << endl;
	return 0;
}