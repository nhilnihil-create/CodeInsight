#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	int ans=100000;
	for (int i=0; i<S.length()-2; i++){
	    int a=stoi(S.substr(i, 3));
	    int diff=abs(753-a);
	    ans=min(ans, diff);
	}
	cout << ans << endl;
}
