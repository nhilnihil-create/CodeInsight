 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int INF = 2147483647;
 const ll MOD = 1000000007;
 // const ll INF = 1000000000000000000LL;

int main() {
	string s;
	cin >> s;
	int left = 0;
	int right = s.size()-1;
	bool can = true;
	int cnt=0;
	while(left<right){
		if(s[left]==s[right]){
			left++;right--;
		}
		else if(s[left]=='x') {
			cnt++;
			left++;
		}
		else if(s[right]=='x'){
			cnt++;
			right--;
		}
		else{
			cout << -1 << endl;
			return 0;
		}
		
	}
	cout << cnt << endl;
	return 0;
}
