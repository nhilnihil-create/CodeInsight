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
	int n;string s;
	cin>>n>>s;
	int ans=0;
	fori(s.length()-1){
		int score=0;
		map<char,bool> m;
		forj(i+1){
			auto itr=m.find(s[j]);
			if(itr==m.end()){
				m[s[j]]=true;
			}
		}
		for(int j=i+1;j<s.length();++j){
			auto itr=m.find(s[j]);
			if(itr!=m.end()&&m[s[j]]){
				m[s[j]]=false;
				++score;
			}
		}
		ans=max(ans,score);
	}
	cout<<ans;
}