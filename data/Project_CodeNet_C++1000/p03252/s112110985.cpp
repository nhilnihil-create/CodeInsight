 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int INF = 2147483647;
 const ll MOD = 1000000007;
 // const ll INF = 1000000000000000000LL;

int main() {
	string s,t;
	cin >> s >> t;
	vector<int> start(26,-1);
	vector<int> goal(26,-1);
	for(int i=0;i<s.size();i++){
		int a = s[i]-'a';
		int b = t[i]-'a';

		if(start[a] !=-1 || goal[b]!=-1){
			if(start[a]!=b ||goal[b]!=a){
				cout << "No" << endl;
				return 0;
			}
		}
		else{
			start[a]=b;
			goal[b]=a;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
