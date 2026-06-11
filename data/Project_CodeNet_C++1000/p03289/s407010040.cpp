#include <bits/stdc++.h>
#define INF 2e9
#define MOD 1000000007
#define MOD9 998244353
#define intMAX 51000;
#define PI 3.14159265359
using namespace std;
typedef long long llong;
typedef long double ldouble;

using Graph = vector<vector<int>>;

int main(){
	string S;
	cin >> S;
	if(S[0] != 'A'){
		cout << "WA" << endl;
		return 0;
	}
	int C = 0;
	for(int i=2; i<S.length()-1; ++i){
		if(S[i] == 'C') ++C;
	}
	if(C != 1){
		cout << "WA" << endl;
		return 0;
	}
	for(int i=1; i<S.length(); ++i){
		if(i==1 || i==S.length()-1) if(isupper(S[i])){
			cout << "WA" << endl;
			return 0;
		}else if(isupper(S[i])) if(S[i] != 'C'){
			cout << "WA" << endl;
			return 0;
		}
	}
	cout << "AC" << endl;
}
