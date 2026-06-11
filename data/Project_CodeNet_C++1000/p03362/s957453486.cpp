#include <iostream>
#include <string>
#include <vector>
#define llint long long

using namespace std;

llint n;
bool prime[60005];
vector<llint> pvec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i = 2; i < 60005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 60005; j+=i){
			prime[j] = true;
		}
	}
	for(int i = 2; i < 55555; i++){
		if(!prime[i] && i % 5 == 1) pvec.push_back(i);
	}
	
	cin >> n;
	for(int i = 0; i < n; i++) cout << pvec[i] << " "; cout << endl;
	
	return 0;
}