#include <iostream>
#include <bitset>
#include <algorithm>

std::bitset<4000000>b;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	int n;
	std::cin >> n;
	
	int a[n];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	
	//std::sort(a, a+n);
	
	long long sum = 0;
	for(int i = 0; i < n; i++)
		sum += a[i];
	
	b[0] = 1;
    for(int i = 0; i < n; i++)
    {
        b |= (b << a[i]);
    }
    
    for(long long i = (sum + 1)/2; i < 2*sum + 5; i++) {
		if(b[i]) {
			std::cout << i << std::endl;
			return 0;
		}
    }
    
    return 0;
}
