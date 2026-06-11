#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;


main(){
	string s;
	cin >> s;
	int win = 0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='o') win++;
	}
	if(win+(15-s.length())>=8){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}

	return 0;
}
