#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

bool compared(string s, string t){
	FOR(i,t.length()) if(t[i]!=s[i] && t[i]!='?') return false;
	return true;
}

int main(){
	string s,t;
	cin >> s >> t;
	//bool flag=false;
	string ans;
	vi v;
	string ans1;
	int i;
	for(i=s.length()-t.length();i>=0;i--){
		if(compared(t,s.substr(i,t.length()))){
			v.PB(i);
		}
	}
	if(!v.empty()){
		for(auto i: v){
			ans1="";
			for(int k=0; k<i;k++) { 
				if(s[k]=='?')ans1+="a";
				else ans1+=s[k];
			}
			ans1=ans1+t;
			int k=i+t.length();
			while(k<s.length()){
				if(s[k]=='?')ans1+="a";
				else ans1+=s[k];
				k++;
			}
			//cout << ans1<<"\n";
			ans=(ans.length()==0)?ans1: min(ans,ans1);
		} 
		cout << ans;
	}
	else cout << "UNRESTORABLE";

	return 0;
}