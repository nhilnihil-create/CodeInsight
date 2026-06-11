#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
	cout << fixed << setprecision(10);
	int n,k;
	string s;
	cin >> n >> k >> s;
	vector<int> nums;
	if(s[0]=='0') nums.push_back(0);
	for(int i=0;i<s.size();){
		int j = i;
		while(j < s.size() && s[j]==s[i]) j++;
		nums.push_back(j-i);
		i = j;
	}
	//cout << endl;
	if(s.back()=='0') nums.push_back(0);
	//cout << endl;
	vector<int> sums((int)nums.size()+1,0);
	for(int i = 0; i < nums.size();i++) sums[i+1] = sums[i] + nums[i];
	//for(int i = 0; i < nums.size();i++) cout << nums[i] << endl;
	int res = 0;
	for(int left = 0 ; left < sums.size(); left += 2){
		int right = left + k*2 + 1;
		if(right >= sums.size()) right = (int)sums.size() - 1;
		res = max(res, sums[right] - sums[left]);
	}
	cout << res << endl;
	return 0;
}