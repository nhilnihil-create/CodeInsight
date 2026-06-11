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
	vector<int> b(n);
	rep(i,n) cin >> b[i];
	vector<int> ans;
	int bn = b.size();
	rep(j,bn){
		for(int i=b.size()-1;i>=0;i--){
			if(b[i]==i+1){
				ans.push_back(b[i]);
				b.erase(b.begin()+i);
				break;
			}
		}
	}
	if(b.size()){
		cout << -1 << endl;
		return 0;
	}
	for(int i=ans.size()-1;i>=0;i--){
		cout << ans[i] << endl;
	}
	return 0;
}
