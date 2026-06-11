#include <bits/stdc++.h>
using namespace std;
std::vector<long long int> v;
int main() {
     long long int n;
	cin >> n;
	long long int g = 0;
	for(long long int i=0;i<n;i+=1){
	     long long int x;
	     cin >> x;
	     g = __gcd(g,x);
	}
	cout << g << endl;
	return 0;
}