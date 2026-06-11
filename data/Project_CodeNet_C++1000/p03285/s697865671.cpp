#include<iostream>

using namespace std;
int main(){
	long long n, count = 0;
	cin >> n;
	
	for(long long i = 0;i<=n/4;i++){
		if((n - 4*i)%7 == 0) {
			count += 1;
			break;
		}
	}
	if(count) cout << "Yes";
	else cout << "No";
}