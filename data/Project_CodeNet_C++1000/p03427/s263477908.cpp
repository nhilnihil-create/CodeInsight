#include <bits/stdc++.h>
using namespace std;
std::vector<int> v;

int main() {
	string N;
	cin >> N;

// 	while(N!=0){
// 	     v.push_back(N%10);
// 	     N/=10;
// 	}
	int sum = 0;
	for(auto x:N){
	     sum+=((int)x)-48;
	    // cout << x << " ";
	}
// 	cout << sum << endl;
     // cout << N.size() << endl;
	int ans = 9*(N.size()-1);
// 	cout << ans << endl;
// 	cout << ((int)N[N.size()-1]) << endl;
	
	ans+=((int)N[0])-49;
	cout  << max(ans,sum) << endl;
	return 0;
}
