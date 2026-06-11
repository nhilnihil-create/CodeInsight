#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	string s,t;
	cin >> s >> t;

	int n = s.size();
	map<char,bool> mp1;
	map<char,char> dict1;
	int now = 0;
	for(int i = 0;i < n;i++){
		if(mp1[s[i]] == false){
			mp1[s[i]] = true;
			dict1[s[i]] = 'a' + now;
			s[i] = 'a' + now;
			now++;
		}
		else{
			s[i] = dict1[s[i]];
		}
	}

	now = 0;
	map<char,bool> mp2;
	map<char,char> dict2;
	for(int i = 0;i < n;i++){
		if(mp2[t[i]] == false){
			mp2[t[i]] = true;
			dict2[t[i]] = 'a' + now;
			t[i] = 'a' + now;
			now++;
		}
		else{
			t[i] = dict2[t[i]];
		}
	}

	if(s == t)cout << "Yes" << endl;
	else cout << "No" << endl;
}
