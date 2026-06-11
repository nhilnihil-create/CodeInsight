#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s,t;
	cin>>s;
	t="AKIHABARA";
	for(int i=0;i<t.size();i++){
		if(s.size()>9){
			cout << "NO";
			return 0;
		}
		if(s[i]!=t[i]){
			s.insert(s.begin()+i,'A');
			i--;
		}
	}
	cout << "YES";
	// your code goes here
	return 0;
}