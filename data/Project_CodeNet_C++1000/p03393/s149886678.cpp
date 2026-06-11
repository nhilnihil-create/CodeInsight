#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

string alphabet = "abcdefghijklmnopqrstuvwxyz";

int main(){
	string s;
	cin >> s;
	map<char,int> mp;
	rep(i,s.size()){
		mp[s[i]]++;
	}
	bool flag = true;
	rep(i,26){
		if(mp[alphabet[i]] == 0) flag = false;
	}
	
	if(!flag){
		rep(i,26){
			if(mp[alphabet[i]] == 0){
				cout << s + alphabet[i] << endl;
				return 0;
			}
		}
	}else{
		vector<int> d;
		rep(i,26){
			int id = s[i] - 'a';
			d.push_back(id);
		}
		
		if(!next_permutation(d.begin(),d.end())){
			cout << -1 << endl;
		}else{
			rep(i,26){
				if(alphabet[d[i]] != s[i]){
					cout << alphabet[d[i]] << endl;
					return 0;
				}else{
					cout << alphabet[d[i]];
				}
			}
		}
	}
    return 0;
}

