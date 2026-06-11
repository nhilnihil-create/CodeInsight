#include<bits/stdc++.h>
using namespace std;

int s;
const int N = 1000000;

int main(void){
	vector<int> a(N, 0);
	cin >> s;
	int i = 1;
	int ans;
	while(true){
		if(a[s] != 0){
			ans = i;
			break;
		}
		a[s] = i++;
		if(s%2 == 0) s/=2;
		else s = 3*s+1;
	}
	cout << ans << endl;
	return 0;
}
