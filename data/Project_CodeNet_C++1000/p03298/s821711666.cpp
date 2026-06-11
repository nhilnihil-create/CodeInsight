#include <iostream>
#include <string>
#include <utility>
#include <map>
#define ll long long
using namespace std;

int main() {
	int N;
	string S;
	cin >> N >> S;
	map<pair<string, string>, int> mp;
	for(int i=0; i<(1<<N); ++i){
		string x="", y="";
		for(int d=0; d<N; ++d){
			if(i&(1<<d)) x += S[d];
			else y += S[d];
		}
		++mp[make_pair(x, y)];
	}
	ll ans=0;
	for(int i=0; i<(1<<N); ++i){
		string x="", y="";
		for(int d=0; d<N; ++d){
			if(i&(1<<d)) x += S[2*N-1-d];
			else y += S[2*N-1-d];
		}
		ans += mp[make_pair(x, y)];
	}
	cout << ans << endl;
	return 0;
}