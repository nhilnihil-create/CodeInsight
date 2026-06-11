#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	string s;
	cin>>s;
	if(s.size() == 26){
		string t = s;
		if(next_permutation(t.begin(), t.end())){
			for(int i = 0; i < 26; i++){
				if(s[i] == t[i]){
					cout<<t[i];
				}else{
					cout<<t[i];
					break;
				}
			}
		}else{
			cout<<-1<<endl;
		}
	}else{
		set<char> st;
		for(auto ch : s){
			st.insert(ch);
		}
		cout<<s;
		for(char x = 'a'; x <= 'z'; x++){
			if(!st.count(x)){
				cout<<x;
				break;
			}
		}
		cout<<endl;
	}

	return 0;
}