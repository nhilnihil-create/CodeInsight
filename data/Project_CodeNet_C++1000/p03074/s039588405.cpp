#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, k;
	cin>>n>>k;
	string s;
	cin>>s;
	char pc = '1';
	vector<int> v({0});
	for(int i = 0; i < n; i++){
		if(s[i] == pc)v.back()++;
		else v.push_back(1);
		pc = s[i];
	}
	if(v.size()%2 == 0)v.push_back(0);
	k = 2*k + 1; int len = v.size();
	if(len <= k){
		cout<<n<<endl;
		exit(0);
	}
	int sum = accumulate(v.begin(), v.begin() + k, 0);
	int ans = sum;
	for(int i = k + 1; i < len; i += 2){
		sum += v[i] + v[i - 1] - v[i - k] - v[i - k - 1];
		ans = max(ans, sum);
	}
	cout<<ans<<endl;

	return 0;
}