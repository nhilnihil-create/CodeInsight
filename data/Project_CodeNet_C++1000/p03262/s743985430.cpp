#include <bits/stdc++.h>
using namespace std;
std::vector<long long int> v;
int main() {
     long long int n;
	cin >> n;
	long long int x;
	cin >> x;
	v.emplace_back(x);
	for(long long int i=0;i<n;i+=1){
	    // long long int x;
	     cin >> x;
	     v.emplace_back(x);
	}
	{
     	sort(v.begin(),v.end());
     	auto x = v[0];
     	long long int g = 0;
          for(long long int i=0;i<=n;i++){
               // cout << g << endl;
               g = __gcd(v[i]-x,g);
          }
     	cout << g;
	}
	return 0;
}