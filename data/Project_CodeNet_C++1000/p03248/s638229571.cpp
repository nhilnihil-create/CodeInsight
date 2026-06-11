#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	int n=S.size();
	if(S[0]=='0' || S[n-1]=='1'){
		cout << -1 << endl;
		return 0;
	}
	for(int i=0; i<n-2-i; ++i){
		if(S[i]!=S[n-2-i]){
			cout << -1 << endl;
			return 0;
		}
	}
	int now=1;
	for(int i=2; i<=n; ++i){
		cout << now << ' ' << i << endl;
		if(S[i-2]=='1'){
			now=i;
		}
	}
	return 0;
}