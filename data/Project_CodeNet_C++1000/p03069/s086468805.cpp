 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int INF = 2147483647;
 const ll MOD = 1000000007;
 // const ll INF = 1000000000000000000LL;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> left_black(n);
	vector<int> right_white(n);
	for(int i=1;i<s.size();i++){
		left_black[i] = left_black[i-1];
		if(s[i-1]=='#') left_black[i]++;
	}
	for(int i=s.size()-2;i>=0;i--){
		right_white[i] = right_white[i+1];
		if(s[i+1]=='.') right_white[i]++;
	}
	// rep(i,s.size()){
	// 	cout << left_black[i] << ':' << right_white[i] << endl;;
	// }
	int ans = INF;
	rep(i,s.size()){
		ans = min(ans,left_black[i]+right_white[i]);
	}
	cout << ans << endl;
	return 0;
}
