#include <stdio.h>
#include <string>
#include <stdlib.h>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<algorithm>
using namespace std;




int main() {
	int n,k;
	cin >> n >> k;
	if(k == 0){
		cout << 1LL * n * n << endl;
		return 0;
	}
	
	unsigned long long int res = 0;
	for(int b=1;b<=n;++b){
		if(b <= k) continue;
		int tmp = b-k;
		res += (n/b)*tmp;
		if(n%b != 0 && n%b >= k)
			res += (n%b)-k+1;
		//cout << b << " " << n/b << " "<< (n/b)*tmp<<endl;
		//cout << n%b <<" " << (n%b)-k<< " " <<endl;
	}
	
	
	cout << res <<endl;
}
