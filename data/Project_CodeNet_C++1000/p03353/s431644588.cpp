#include <iostream>
#include <string>
#include <set>
#define rep(i,s,N) for(int i=s;i<N;i++)
using namespace std;

int main(void)
{
	string s; cin >> s;
	int K; cin >> K;
	set<string> substring;

	rep(i, 1, K + 1) {
		rep(j, 0, s.length()) {
			string tmp = s.substr(j, i);
			substring.insert(tmp);
		}
	}
	set<string>::iterator it = substring.begin();
	rep(i, 1, K)it++;
	cout << *it << endl;

	return 0;
}