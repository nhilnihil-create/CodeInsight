#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
	string s, t;
	cin >> s >> t;
	
	rep(i, s.size()){
		if(s == t){
			cout << "Yes" << endl;
			return 0;
		}

		s = s.back() + s.substr(0, s.size()-1);
	}
	cout << "No" << endl;
    return 0;
}