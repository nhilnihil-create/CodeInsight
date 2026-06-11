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
clock_t startTime;
long double getTime(){
	return (long double)(clock()-startTime)/CLOCKS_PER_SEC;
}

string s;
string t;

string func(){
	if(s.length()!=t.length()) return "No";
	else{
		int n=s.length();
		for(char c='a'; c <='z';c++){
			std::vector<int> v;
			std::vector<int> w;
			FOR(i,n){
				if(s[i]==c) v.PB(i);
				if(t[i]==c) w.PB(i);
			}
			//if(c=='e') error(v.size(),w.size(),s.length());
			if(v.size()>0){
				char a=t[v[0]];
				for(int j=1;j < v.size();j++) if(t[v[j]]!=a) return "No";
			}
			if(w.size()>0){
				char b=s[w[0]];
				for(int k=1;k<w.size();k++) if(s[w[k]]!=b) return "No";
			}
		}
		return "Yes";
	}
}

int main(){
	startTime=clock();
	
	cin >> s >> t;
	cout << func();

	return 0;
}