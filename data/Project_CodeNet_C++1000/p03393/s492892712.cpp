#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

using namespace std;

#define fori(x) for (int i = 0; i < x; ++i)
#define forj(x) for (int j = 0; j < x; ++j)

typedef long long ll;

const int INF = 2e9 + 5;
const int alength=100100;

int main() {
	string s;
	cin>>s;
	if(s.length()<26){
		map<char,bool> m;
		fori(s.length()){
			m[s[i]]=true;
		}
		for(char c='a';c<='z';++c){
			auto itr=m.find(c);
			if(itr==m.end()){
				cout<<s<<c;
				return 0;
			}
		}
		return 0;
	}else{
		if(s=="zyxwvutsrqponmlkjihgfedcba"){
			cout<<-1;
			return 0;
		}
		string t=s;
		next_permutation(t.begin(),t.end());
		fori(26){
			if(s[i]==t[i])
				cout<<t[i];
			else{
				cout<<t[i];return 0;
			}
		}
	}
}