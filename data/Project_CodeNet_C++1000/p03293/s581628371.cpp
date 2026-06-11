#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s,t;
	cin >> s >> t;
	int len = s.size();
    string u = s;
	rep(i,len){
		u = u[len-1] + u;
		u.erase(len);
		if(u == t){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}