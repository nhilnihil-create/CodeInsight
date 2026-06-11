#include <iostream>
#include <bitset>
#include <algorithm>

std::bitset<4000000>b[2];

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	int n;
	std::cin >> n;
	
	int a[n];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	
	std::sort(a, a+n);
	
	long long sum = 0;
	for(int i = 0; i < n; i++)
		sum += a[i];
	
	b[0].set(0,1);
    b[0].set(a[0],1);
    for(int i = 1; i < n; i++)
    {
        b[i&1]=b[i&1]|b[!(i&1)];
        b[i&1]=b[i&1]|(b[!(i&1)]<<a[i]);
    }
    sum++;
    sum/=2;
    for(long long i = sum; i < 2*sum + 5; i++) {
		if(b[(n-1)&1][i]) {
			std::cout << i << std::endl;
			return 0;
		}
    }
    
    return 0;
}
