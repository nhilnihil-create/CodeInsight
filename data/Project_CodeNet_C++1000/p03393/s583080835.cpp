#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	
	if(s == "zyxwvutsrqponmlkjihgfedcba"){
		cout << -1 << endl;
		return 0;
	}
	
	
	if(s.size() < 26){
		vector<P> alph(26);
		rep(i, 26) alph[i] = make_pair(0, i);
		
		rep(i, s.size()){
			alph[s[i] - 'a'].first++;
			alph[s[i] - 'a'].second = s[i] - 'a';
		}
		sort(alph.begin(), alph.end());
		s += (char)alph[0].second + 'a';
		cout << s << endl;
	}
	else{
		string tmp = s;
		next_permutation(s.begin(), s.end());
		rep(i, 26){
			if(s[i] == tmp[i]){
				cout << s[i];
			}
			else{
				cout << s[i] << endl;
				return 0;
			}
		}
	}
	
	return 0;
}

