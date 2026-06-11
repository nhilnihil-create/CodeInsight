#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

	int a, b;
	string s;
	cin >> a >> b >> s;

	if(a+b+1 != s.size()){
		cout << "No"<< endl;
	}else{
		bool ans = true;
		int i = 0;
		int n = s.size();
		for(; i < a; i++){
			if(s[i]=='-')ans = false;
		}
		if(s[i] != '-')ans = false;
		i++;
		for(; i < n; i++){
			if(s[i]=='-')ans = false;
		}
		if(ans) cout << "Yes" << endl;
		else cout << "No"<< endl;
	}



}


