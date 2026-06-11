#include <iostream>
#include <bitset>

using namespace std;

int n;
int a[2005];
bitset<4000005> bs;

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int sum = 0, mid;
	for(int i = 1; i <= n; i++) sum += a[i];
	mid = (sum+1)/2;
	
	bs[0] = true;
	for(int i = 1; i <= n; i++) bs |= bs << a[i];
	for(int i = mid; i <= 4000000; i++){
		if(bs[i]){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}